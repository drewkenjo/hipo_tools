using v_int   = std::vector<Int_t>;
using v_float = std::vector<Float_t>;

// Old Event
int   NRUN;
int   NEVENT;
float EVNTime;
int   TYPE;
int   TRG;
float BCG;
float STTime;
// float  RFTime;
int    Helic;
int    EvCAT;
int    NPGP;
double LT;
float  PTIME;

int    category;
int    topology;
float  beamCharge;
double liveTime;
float  startTime;
float  RFTime;
int    helicity;
int    helicityRaw;
float  procTime;

v_int   pid;
v_float p;
v_float p2;
v_float px;
v_float py;
v_float pz;
v_float vx;
v_float vy;
v_float vz;
v_int   charge;
v_float beta;
v_float chi2pid;
v_int   status;

v_int   dc_sec;
v_float dc_px;
v_float dc_py;
v_float dc_pz;
v_float dc_vx;
v_float dc_vy;
v_float dc_vz;
v_float dc_r1_x;
v_float dc_r1_y;
v_float dc_r1_z;
v_float dc_r2_x;
v_float dc_r2_y;
v_float dc_r2_z;
v_float dc_r3_x;
v_float dc_r3_y;
v_float dc_r3_z;

v_float cvt_px;
v_float cvt_py;
v_float cvt_pz;
v_float cvt_vx;
v_float cvt_vy;
v_float cvt_vz;
v_float cvt_l1_x;
v_float cvt_l1_y;
v_float cvt_l1_z;
v_float cvt_l2_x;
v_float cvt_l2_y;
v_float cvt_l2_z;
v_float cvt_l3_x;
v_float cvt_l3_y;
v_float cvt_l3_z;
v_float cvt_l4_x;
v_float cvt_l4_y;
v_float cvt_l4_z;
v_float cvt_l5_x;
v_float cvt_l5_y;
v_float cvt_l5_z;
v_float cvt_l6_x;
v_float cvt_l6_y;
v_float cvt_l6_z;
v_float cvt_l7_x;
v_float cvt_l7_y;
v_float cvt_l7_z;
v_float cvt_l8_x;
v_float cvt_l8_y;
v_float cvt_l8_z;
v_float cvt_l9_x;
v_float cvt_l9_y;
v_float cvt_l9_z;
v_float cvt_l10_x;
v_float cvt_l10_y;
v_float cvt_l10_z;
v_float cvt_l11_x;
v_float cvt_l11_y;
v_float cvt_l11_z;
v_float cvt_l12_x;
v_float cvt_l12_y;
v_float cvt_l12_z;

v_float fmt_p1_x;
v_float fmt_p1_y;
v_float fmt_p1_z;
v_float fmt_p2_x;
v_float fmt_p2_y;
v_float fmt_p2_z;
v_float fmt_p3_x;
v_float fmt_p3_y;
v_float fmt_p3_z;
v_float fmt_p4_x;
v_float fmt_p4_y;
v_float fmt_p4_z;
v_float fmt_p5_x;
v_float fmt_p5_y;
v_float fmt_p5_z;
v_float fmt_p6_x;
v_float fmt_p6_y;
v_float fmt_p6_z;

v_float ec_tot_energy;
v_float ec_pcal_energy;
v_int   ec_pcal_sec;
v_float ec_pcal_time;
v_float ec_pcal_path;
v_float ec_pcal_x;
v_float ec_pcal_y;
v_float ec_pcal_z;
v_float ec_pcal_hx;
v_float ec_pcal_hy;
v_float ec_pcal_hz;
v_float ec_pcal_lu;
v_float ec_pcal_lv;
v_float ec_pcal_lw;
v_float ec_pcal_du;
v_float ec_pcal_dv;
v_float ec_pcal_dw;
v_float ec_pcal_m2u;
v_float ec_pcal_m2v;
v_float ec_pcal_m2w;
v_float ec_pcal_m3u;
v_float ec_pcal_m3v;
v_float ec_pcal_m3w;

v_float ec_ecin_energy;
v_int   ec_ecin_sec;
v_float ec_ecin_time;
v_float ec_ecin_path;
v_float ec_ecin_x;
v_float ec_ecin_y;
v_float ec_ecin_z;
v_float ec_ecin_hx;
v_float ec_ecin_hy;
v_float ec_ecin_hz;
v_float ec_ecin_lu;
v_float ec_ecin_lv;
v_float ec_ecin_lw;
v_float ec_ecin_du;
v_float ec_ecin_dv;
v_float ec_ecin_dw;
v_float ec_ecin_m2u;
v_float ec_ecin_m2v;
v_float ec_ecin_m2w;
v_float ec_ecin_m3u;
v_float ec_ecin_m3v;
v_float ec_ecin_m3w;

v_float ec_ecout_energy;
v_int   ec_ecout_sec;
v_float ec_ecout_time;
v_float ec_ecout_path;
v_float ec_ecout_x;
v_float ec_ecout_y;
v_float ec_ecout_z;
v_float ec_ecout_hx;
v_float ec_ecout_hy;
v_float ec_ecout_hz;
v_float ec_ecout_lu;
v_float ec_ecout_lv;
v_float ec_ecout_lw;
v_float ec_ecout_du;
v_float ec_ecout_dv;
v_float ec_ecout_dw;
v_float ec_ecout_m2u;
v_float ec_ecout_m2v;
v_float ec_ecout_m2w;
v_float ec_ecout_m3u;
v_float ec_ecout_m3v;
v_float ec_ecout_m3w;

v_float cc_nphe_tot;
v_int   cc_ltcc_sec;
v_float cc_ltcc_nphe;
v_float cc_ltcc_time;
v_float cc_ltcc_path;
v_float cc_ltcc_theta;
v_float cc_ltcc_phi;
v_float cc_ltcc_x;
v_float cc_ltcc_y;
v_float cc_ltcc_z;
v_int   cc_htcc_sec;
v_float cc_htcc_nphe;
v_float cc_htcc_time;
v_float cc_htcc_path;
v_float cc_htcc_theta;
v_float cc_htcc_phi;
v_float cc_htcc_x;
v_float cc_htcc_y;
v_float cc_htcc_z;
v_int   cc_rich_sec;
v_float cc_rich_nphe;
v_float cc_rich_time;
v_float cc_rich_path;
v_float cc_rich_theta;
v_float cc_rich_phi;
v_float cc_rich_x;
v_float cc_rich_y;
v_float cc_rich_z;

v_int   sc_ftof_1a_sec;
v_float sc_ftof_1a_time;
v_float sc_ftof_1a_path;
v_float sc_ftof_1a_energy;
v_int   sc_ftof_1a_component;
v_float sc_ftof_1a_x;
v_float sc_ftof_1a_y;
v_float sc_ftof_1a_z;
v_float sc_ftof_1a_hx;
v_float sc_ftof_1a_hy;
v_float sc_ftof_1a_hz;

v_int   sc_ftof_1b_sec;
v_float sc_ftof_1b_time;
v_float sc_ftof_1b_path;
v_float sc_ftof_1b_energy;
v_int   sc_ftof_1b_component;
v_float sc_ftof_1b_x;
v_float sc_ftof_1b_y;
v_float sc_ftof_1b_z;
v_float sc_ftof_1b_hx;
v_float sc_ftof_1b_hy;
v_float sc_ftof_1b_hz;

v_int   sc_ftof_2_sec;
v_float sc_ftof_2_time;
v_float sc_ftof_2_path;
v_float sc_ftof_2_energy;
v_int   sc_ftof_2_component;
v_float sc_ftof_2_x;
v_float sc_ftof_2_y;
v_float sc_ftof_2_z;
v_float sc_ftof_2_hx;
v_float sc_ftof_2_hy;
v_float sc_ftof_2_hz;

v_float sc_ctof_time;
v_float sc_ctof_path;
v_float sc_ctof_energy;
v_int   sc_ctof_component;
v_float sc_ctof_x;
v_float sc_ctof_y;
v_float sc_ctof_z;
v_float sc_ctof_hx;
v_float sc_ctof_hy;
v_float sc_ctof_hz;

v_float sc_cnd_time;
v_float sc_cnd_path;
v_float sc_cnd_energy;
v_int   sc_cnd_component;
v_float sc_cnd_x;
v_float sc_cnd_y;
v_float sc_cnd_z;
v_float sc_cnd_hx;
v_float sc_cnd_hy;
v_float sc_cnd_hz;

v_float ft_cal_energy;
v_float ft_cal_time;
v_float ft_cal_path;
v_float ft_cal_x;
v_float ft_cal_y;
v_float ft_cal_z;
v_float ft_cal_dx;
v_float ft_cal_dy;
v_float ft_cal_radius;

v_float ft_hodo_energy;
v_float ft_hodo_time;
v_float ft_hodo_path;
v_float ft_hodo_x;
v_float ft_hodo_y;
v_float ft_hodo_z;
v_float ft_hodo_dx;
v_float ft_hodo_dy;
v_float ft_hodo_radius;

int   mc_run;
int   mc_event;
int   mc_type;
float mc_helicity;

v_int   mc_pid_vec;
v_float mc_px_vec;
v_float mc_py_vec;
v_float mc_pz_vec;
v_float mc_vx_vec;
v_float mc_vy_vec;
v_float mc_vz_vec;
v_float mc_vt_vec;

v_int   MC_pid;
v_float MC_helicity;
v_float MC_px;
v_float MC_py;
v_float MC_pz;
v_float MC_vx;
v_float MC_vy;
v_float MC_vz;
v_float MC_vt;

v_int   Lund_pid;
v_float Lund_px;
v_float Lund_py;
v_float Lund_pz;
v_float Lund_E;
v_float Lund_vx;
v_float Lund_vy;
v_float Lund_vz;
v_float Lund_ltime;

v_float CovMat_11;
v_float CovMat_12;
v_float CovMat_13;
v_float CovMat_14;
v_float CovMat_15;
v_float CovMat_22;
v_float CovMat_23;
v_float CovMat_24;
v_float CovMat_25;
v_float CovMat_33;
v_float CovMat_34;
v_float CovMat_35;
v_float CovMat_44;
v_float CovMat_45;
v_float CovMat_55;

v_int   VertDoca_index1_vec;
v_int   VertDoca_index2_vec;
v_float VertDoca_x_vec;
v_float VertDoca_y_vec;
v_float VertDoca_z_vec;
v_float VertDoca_x1_vec;
v_float VertDoca_y1_vec;
v_float VertDoca_z1_vec;
v_float VertDoca_cx1_vec;
v_float VertDoca_cy1_vec;
v_float VertDoca_cz1_vec;
v_float VertDoca_x2_vec;
v_float VertDoca_y2_vec;
v_float VertDoca_z2_vec;
v_float VertDoca_cx2_vec;
v_float VertDoca_cy2_vec;
v_float VertDoca_cz2_vec;
v_float VertDoca_r_vec;

v_int   traj_pindex_vec;
v_int   traj_index_vec;
v_int   traj_detId_vec;
v_int   traj_q_vec;
v_float traj_x_vec;
v_float traj_y_vec;
v_float traj_z_vec;
v_float traj_cx_vec;
v_float traj_cy_vec;
v_float traj_cz_vec;
v_float traj_pathlength_vec;