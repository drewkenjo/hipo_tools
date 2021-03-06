/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "hipo4/recordbuilder.h"

#ifdef __LZ4__
#include <lz4.h>
#endif

namespace hipo {

  recordbuilder::recordbuilder() {
    bufferIndex.resize(4 * defaultNumberOfEvents);
    bufferEvents.resize(defaultRecordSize);
    bufferData.resize(defaultRecordSize + 4 * defaultNumberOfEvents);
    bufferRecord.resize(defaultRecordSize + 4 * defaultNumberOfEvents + 512 * 1024);

    bufferIndexEntries   = 0;
    bufferEventsPosition = 0;
  }

  recordbuilder::recordbuilder(int maxEvents, int maxLength) {
    bufferIndex.resize(4 * maxEvents);
    bufferEvents.resize(maxLength);
    bufferData.resize(maxLength + 4 * maxEvents + 1024);
    bufferRecord.resize(maxLength + 4 * maxEvents + 512 * 1024);
    bufferIndexEntries   = 0;
    bufferEventsPosition = 0;
  }

  bool recordbuilder::addEvent(hipo::event& evnt) {
    return addEvent(evnt.getEventBuffer(), 0, evnt.getSize());
  }

  bool recordbuilder::addEvent(std::vector<char>& vec, int start, int length) {
    if ((bufferEventsPosition + length) >= bufferEvents.size())
      return false;
    if ((bufferIndexEntries + 1) * 4 >= bufferIndex.size())
      return false;
    *reinterpret_cast<int*>(&bufferIndex[bufferIndexEntries * 4]) = length;
    bufferIndexEntries++;
    memcpy(&bufferEvents[bufferEventsPosition], &vec[start], length);
    bufferEventsPosition += length;
    return true;
  }

  void recordbuilder::reset() {
    bufferIndexEntries   = 0;
    bufferEventsPosition = 0;
  }

  int recordbuilder::getRecordLengthRounding(int bufferSize) {
    int nwords = bufferSize / 4;
    int nbytes = 4 * nwords;
    return (bufferSize - nbytes);
  }
  /**
   * Returns number of events in the record.
   */
  int recordbuilder::getEntries() {
    int nentries = *reinterpret_cast<int*>(&bufferRecord[12]);
    return nentries;
  }

  long recordbuilder::getUserWordOne() {
    long wOne = *reinterpret_cast<long*>(&bufferRecord[40]);
    return wOne;
  }

  long recordbuilder::getUserWordTwo() {
    long wTwo = *reinterpret_cast<long*>(&bufferRecord[48]);
    return wTwo;
  }

  int recordbuilder::getRecordSize() {
    int size = *reinterpret_cast<int*>(&bufferRecord[0]);
    return size * 4;
  }

  void recordbuilder::build() {
    int indexSize  = bufferIndexEntries * 4;
    int eventsSize = bufferEventsPosition;
    memcpy(&bufferData[0], &bufferIndex[0], indexSize);
    memcpy(&bufferData[indexSize], &bufferEvents[0], eventsSize);
    int uncompressedSize           = indexSize + eventsSize;
    int compressedSize             = compressRecord(uncompressedSize);
    int rounding                   = getRecordLengthRounding(compressedSize);
    int compressedSizeToWrite      = compressedSize + rounding;
    int compressedSizeToWriteWords = compressedSizeToWrite / 4;
    int recordLength               = compressedSizeToWrite / 4 + 14;

    hipo::utils::writeInt(&bufferRecord[0], 0,
                          recordLength);           // (1) - record length in words (includes header)
    hipo::utils::writeInt(&bufferRecord[0], 4, 0); // (2) - record #
    hipo::utils::writeInt(&bufferRecord[0], 8, 14); // (3) - record header lenght (in words)
    hipo::utils::writeInt(&bufferRecord[0], 12,
                          bufferIndexEntries); // (4) event count in the record
    hipo::utils::writeInt(&bufferRecord[0], 16,
                          bufferIndexEntries * 4); // (5) length of index array in bytes
    int versionWord = (rounding << 24) | (4);
    hipo::utils::writeInt(&bufferRecord[0], 20, versionWord); // (6) record version number
    hipo::utils::writeInt(&bufferRecord[0], 24, 0);           // (7) user header length bytes
    hipo::utils::writeInt(&bufferRecord[0], 28, 0xc0da0100);  // (8) magic word
    hipo::utils::writeInt(&bufferRecord[0], 32, eventsSize);  // (9) magic word
    int compressionWord = (1 << 28) | (0x0FFFFFFF & compressedSizeToWriteWords);
    hipo::utils::writeInt(&bufferRecord[0], 36, compressionWord);
    hipo::utils::writeLong(&bufferRecord[0], 40, 0);
    hipo::utils::writeLong(&bufferRecord[0], 48, 0);
  }

  int recordbuilder::compressRecord(int src_size) {

#ifdef __LZ4__
    //(const char* src, char* dst, int srcSize, int dstCapacity, int acceleration);
    int result =
        LZ4_compress_fast(&bufferData[0], &bufferRecord[56], src_size, bufferRecord.size(), 3);
    // int   result = LZ4_decompress_safe(data,output,dataLength,dataLengthUncompressed);
    // int   result = LZ4_decompress_fast(data,output,dataLengthUncompressed);
    return result;
#endif

#ifndef __LZ4__
    printf("\n   >>>>> LZ4 compression is not supported.");
    printf("\n   >>>>> check if libz4 is installed on your system.");
    printf("\n   >>>>> recompile the library with liblz4 installed.\n");
    return 0;
#endif
  }
} // namespace hipo
