#include "clipp.h"
#include "hipo4/writer.h"
#include <TFile.h>
#include <TROOT.h>
#include <TTree.h>
#include <cstdlib>
#include <iostream>
#include <locale>

int main(int argc, char** argv) {
  ROOT::EnableThreadSafety();
  ROOT::EnableImplicitMT(2);
  std::string inputFile  = "";
  std::string outputFile = "recon2root.out";
  bool        is_mc      = false;
  bool        print_help = false;
  bool        hipo_file  = false;

  auto cli =
      (clipp::option("-h", "--help").set(print_help) % "print help",
       clipp::option("-mc", "--MC").set(is_mc) % "Convert dst and mc banks",
       clipp::option("-hipo", "--hipo").set(hipo_file) % "Save hipo file",
       clipp::value("inputFile.hipo", inputFile), clipp::opt_value("outputFile", outputFile));

  clipp::parse(argc, argv, cli);
  if (print_help || argc <= 2) {
    std::cerr << clipp::make_man_page(cli, argv[0]);
    exit(1);
  } else if (inputFile.find("hipo") == std::string::npos) {
    std::cerr << "Input file needs to be hipo file => " << inputFile << std::endl;
    exit(2);
  }

  auto reader = std::make_unique<hipo::reader>(inputFile);
  auto dict   = std::make_unique<hipo::dictionary>();
  reader->readDictionary(*dict);

  auto OutputFile = std::make_unique<TFile>((outputFile + ".root").c_str(), "RECREATE");
  OutputFile->SetCompressionSettings(404); // kUseAnalysis
  auto clas12 = std::make_unique<TTree>("clas12", "clas12");

  Int_t   gpart;
  Int_t   pid[kMaxChar];
  Float_t px[kMaxChar];
  Float_t py[kMaxChar];
  Float_t pz[kMaxChar];
  Float_t vx[kMaxChar];
  Float_t vy[kMaxChar];
  Float_t vz[kMaxChar];
  Float_t vt[kMaxChar];
  Int_t   charge[kMaxChar];
  Float_t beta[kMaxChar];
  Float_t chi2pid[kMaxChar];
  Int_t   status[kMaxChar];

  clas12->Branch("gpart", &gpart, "gpart/I");
  clas12->Branch("pid", pid, "pid[gpart]/I");
  clas12->Branch("px", px, "px[gpart]/F");
  clas12->Branch("py", py, "py[gpart]/F");
  clas12->Branch("pz", pz, "pz[gpart]/F");
  clas12->Branch("vx", vx, "vx[gpart]/F");
  clas12->Branch("vy", vy, "vy[gpart]/F");
  clas12->Branch("vz", vz, "vz[gpart]/F");
  clas12->Branch("vt", vt, "vt[gpart]/F");
  clas12->Branch("charge", charge, "charge[gpart]/I");
  clas12->Branch("beta", beta, "beta[gpart]/F");
  clas12->Branch("chi2pid", chi2pid, "chi2pid[gpart]/F");
  clas12->Branch("status", status, "status[gpart]/I");

  std::unique_ptr<hipo::writer> writer;
  if (hipo_file) {
    writer = std::make_unique<hipo::writer>((outputFile + ".hipo").c_str());
    writer->getDictionary().addSchema(dict->getSchema("REC::Particle"));
  }

  reader->readDictionary(*dict);
  auto rec_Particle = std::make_shared<hipo::bank>(dict->getSchema("REC::Particle"));

  auto event    = std::make_unique<hipo::event>();
  auto outEvent = std::make_unique<hipo::event>();

  Long64_t entry      = 0LL;
  auto     start_full = std::chrono::high_resolution_clock::now();

  while (reader->next()) {
    entry++;
    reader->read(*event);
    event->getStructure(*rec_Particle);
    if (rec_Particle->getRows() > 0) {
      if (rec_Particle->getInt(0, 0) != 11)
        continue;

      if (hipo_file) {
        outEvent->reset();
        outEvent->addStructure(*rec_Particle);
        writer->addEvent(*outEvent);
      }

      gpart = rec_Particle->getRows();
      for (int i = 0; i < gpart; i++) {
        pid[i]     = rec_Particle->getInt(0, i);
        px[i]      = rec_Particle->getFloat(1, i);
        py[i]      = rec_Particle->getFloat(2, i);
        pz[i]      = rec_Particle->getFloat(3, i);
        vx[i]      = rec_Particle->getFloat(4, i);
        vy[i]      = rec_Particle->getFloat(5, i);
        vz[i]      = rec_Particle->getFloat(6, i);
        vt[i]      = rec_Particle->getFloat(7, i);
        charge[i]  = rec_Particle->getInt(8, i);
        beta[i]    = ((rec_Particle->getFloat(9, i) != -9999) ? rec_Particle->getFloat(9, i) : NAN);
        chi2pid[i] = rec_Particle->getFloat(10, i);
        status[i]  = rec_Particle->getInt(11, i);
      }
      clas12->Fill();
    }
  }

  std::chrono::duration<double> elapsed_full =
      (std::chrono::high_resolution_clock::now() - start_full);
  std::cout.imbue(std::locale(""));
  std::cout << "Elapsed time: " << elapsed_full.count() << " s" << std::endl;
  std::cout << "Events/Sec: " << entry / elapsed_full.count() << " Hz" << std::endl;
  std::cout << "Total events in file: " << entry << std::endl;

  OutputFile->cd();
  clas12->Write();
  OutputFile->Write();

  return 0;
}
