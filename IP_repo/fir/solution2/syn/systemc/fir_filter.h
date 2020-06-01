// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and OpenCL
// Version: 2019.2
// Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

#ifndef _fir_filter_HH_
#define _fir_filter_HH_

#include "systemc.h"
#include "AESL_pkg.h"

#include "fir_filter_shift_bkb.h"
#include "fir_filter_c.h"

namespace ap_rtl {

struct fir_filter : public sc_module {
    // Port declarations 10
    sc_in_clk ap_clk;
    sc_in< sc_logic > ap_rst_n;
    sc_in< sc_lv<32> > datain_TDATA;
    sc_in< sc_logic > datain_TVALID;
    sc_out< sc_logic > datain_TREADY;
    sc_in< sc_lv<1> > datain_TLAST;
    sc_out< sc_lv<32> > dataout_TDATA;
    sc_out< sc_logic > dataout_TVALID;
    sc_in< sc_logic > dataout_TREADY;
    sc_out< sc_lv<1> > dataout_TLAST;


    // Module declarations
    fir_filter(sc_module_name name);
    SC_HAS_PROCESS(fir_filter);

    ~fir_filter();

    sc_trace_file* mVcdFile;

    ofstream mHdltvinHandle;
    ofstream mHdltvoutHandle;
    fir_filter_shift_bkb* shift_reg_left_V_U;
    fir_filter_c* c_U;
    fir_filter_shift_bkb* shift_reg_right_V_U;
    regslice_both<32>* regslice_both_datain_data_V_U;
    regslice_both<1>* regslice_both_datain_last_V_U;
    regslice_both<32>* regslice_both_dataout_data_V_U;
    regslice_both<1>* regslice_both_dataout_last_V_U;
    sc_signal< sc_logic > ap_rst_n_inv;
    sc_signal< sc_lv<6> > shift_reg_left_V_address0;
    sc_signal< sc_logic > shift_reg_left_V_ce0;
    sc_signal< sc_lv<32> > shift_reg_left_V_q0;
    sc_signal< sc_lv<6> > shift_reg_left_V_address1;
    sc_signal< sc_logic > shift_reg_left_V_ce1;
    sc_signal< sc_logic > shift_reg_left_V_we1;
    sc_signal< sc_lv<32> > shift_reg_left_V_d1;
    sc_signal< sc_lv<6> > c_address0;
    sc_signal< sc_logic > c_ce0;
    sc_signal< sc_lv<16> > c_q0;
    sc_signal< sc_lv<6> > shift_reg_right_V_address0;
    sc_signal< sc_logic > shift_reg_right_V_ce0;
    sc_signal< sc_lv<32> > shift_reg_right_V_q0;
    sc_signal< sc_lv<6> > shift_reg_right_V_address1;
    sc_signal< sc_logic > shift_reg_right_V_ce1;
    sc_signal< sc_logic > shift_reg_right_V_we1;
    sc_signal< sc_lv<32> > shift_reg_right_V_d1;
    sc_signal< sc_logic > datain_TDATA_blk_n;
    sc_signal< sc_lv<14> > ap_CS_fsm;
    sc_signal< sc_logic > ap_CS_fsm_state9;
    sc_signal< sc_logic > ap_CS_fsm_state17;
    sc_signal< sc_logic > dataout_TDATA_blk_n;
    sc_signal< sc_logic > ap_CS_fsm_state11;
    sc_signal< sc_logic > ap_CS_fsm_state12;
    sc_signal< sc_logic > ap_CS_fsm_state19;
    sc_signal< sc_logic > ap_CS_fsm_state20;
    sc_signal< sc_lv<53> > p_0403_0_reg_179;
    sc_signal< sc_lv<6> > i_0_reg_189;
    sc_signal< sc_lv<53> > p_0412_0_reg_200;
    sc_signal< sc_lv<6> > i_1_reg_210;
    sc_signal< sc_lv<32> > reg_229;
    sc_signal< sc_logic > ap_CS_fsm_state2;
    sc_signal< sc_logic > ap_CS_fsm_pp0_stage0;
    sc_signal< sc_logic > ap_enable_reg_pp0_iter1;
    sc_signal< bool > ap_block_state5_pp0_stage0_iter0;
    sc_signal< bool > ap_block_state6_pp0_stage0_iter1;
    sc_signal< bool > ap_block_state7_pp0_stage0_iter2;
    sc_signal< bool > ap_block_state8_pp0_stage0_iter3;
    sc_signal< bool > ap_block_pp0_stage0_11001;
    sc_signal< sc_lv<1> > icmp_ln51_reg_477;
    sc_signal< sc_lv<16> > reg_233;
    sc_signal< sc_logic > ap_CS_fsm_pp1_stage0;
    sc_signal< sc_logic > ap_enable_reg_pp1_iter1;
    sc_signal< bool > ap_block_state13_pp1_stage0_iter0;
    sc_signal< bool > ap_block_state14_pp1_stage0_iter1;
    sc_signal< bool > ap_block_state15_pp1_stage0_iter2;
    sc_signal< bool > ap_block_state16_pp1_stage0_iter3;
    sc_signal< bool > ap_block_pp1_stage0_11001;
    sc_signal< sc_lv<1> > icmp_ln98_reg_542;
    sc_signal< sc_lv<32> > reg_237;
    sc_signal< sc_logic > ap_CS_fsm_state10;
    sc_signal< sc_lv<42> > acc_left_V_fu_245_p2;
    sc_signal< sc_lv<42> > acc_left_V_reg_467;
    sc_signal< sc_logic > ap_CS_fsm_state3;
    sc_signal< sc_lv<53> > sext_ln68_1_fu_251_p1;
    sc_signal< sc_logic > ap_CS_fsm_state4;
    sc_signal< sc_lv<1> > icmp_ln51_fu_254_p2;
    sc_signal< sc_lv<1> > icmp_ln51_reg_477_pp0_iter1_reg;
    sc_signal< sc_lv<1> > icmp_ln51_reg_477_pp0_iter2_reg;
    sc_signal< sc_lv<6> > i_fu_260_p2;
    sc_signal< sc_lv<6> > i_reg_481;
    sc_signal< sc_logic > ap_enable_reg_pp0_iter0;
    sc_signal< sc_lv<64> > zext_ln58_1_fu_271_p1;
    sc_signal< sc_lv<64> > zext_ln58_1_reg_491;
    sc_signal< sc_lv<48> > mul_ln700_fu_284_p2;
    sc_signal< sc_lv<48> > mul_ln700_reg_501;
    sc_signal< sc_lv<53> > acc_left_V_2_fu_293_p2;
    sc_signal< sc_logic > ap_enable_reg_pp0_iter3;
    sc_signal< sc_lv<1> > datain_last_V_val_reg_511;
    sc_signal< sc_lv<32> > datain_left_V_2_fu_313_p3;
    sc_signal< sc_lv<32> > datain_left_V_2_reg_516;
    sc_signal< sc_lv<42> > mul_ln700_1_fu_324_p2;
    sc_signal< sc_lv<42> > mul_ln700_1_reg_522;
    sc_signal< sc_lv<42> > acc_right_V_fu_358_p2;
    sc_signal< sc_lv<42> > acc_right_V_reg_532;
    sc_signal< sc_lv<53> > sext_ln68_3_fu_364_p1;
    sc_signal< sc_lv<1> > icmp_ln98_fu_367_p2;
    sc_signal< sc_lv<1> > icmp_ln98_reg_542_pp1_iter1_reg;
    sc_signal< sc_lv<1> > icmp_ln98_reg_542_pp1_iter2_reg;
    sc_signal< sc_lv<6> > i_2_fu_373_p2;
    sc_signal< sc_lv<6> > i_2_reg_546;
    sc_signal< sc_logic > ap_enable_reg_pp1_iter0;
    sc_signal< sc_lv<64> > zext_ln99_1_fu_384_p1;
    sc_signal< sc_lv<64> > zext_ln99_1_reg_556;
    sc_signal< sc_lv<48> > mul_ln700_2_fu_397_p2;
    sc_signal< sc_lv<48> > mul_ln700_2_reg_566;
    sc_signal< sc_lv<53> > acc_right_V_2_fu_406_p2;
    sc_signal< sc_logic > ap_enable_reg_pp1_iter3;
    sc_signal< sc_lv<1> > datain_last_V_val8_reg_576;
    sc_signal< sc_lv<32> > datain_right_V_2_fu_426_p3;
    sc_signal< sc_lv<32> > datain_right_V_2_reg_581;
    sc_signal< sc_lv<42> > mul_ln700_3_fu_437_p2;
    sc_signal< sc_lv<42> > mul_ln700_3_reg_587;
    sc_signal< sc_logic > ap_CS_fsm_state18;
    sc_signal< bool > ap_block_pp0_stage0_subdone;
    sc_signal< sc_logic > ap_condition_pp0_exit_iter0_state5;
    sc_signal< sc_logic > ap_enable_reg_pp0_iter2;
    sc_signal< bool > ap_block_pp1_stage0_subdone;
    sc_signal< sc_logic > ap_condition_pp1_exit_iter0_state13;
    sc_signal< sc_logic > ap_enable_reg_pp1_iter2;
    sc_signal< sc_lv<6> > ap_phi_mux_i_0_phi_fu_193_p4;
    sc_signal< bool > ap_block_pp0_stage0;
    sc_signal< sc_lv<6> > ap_phi_mux_i_1_phi_fu_214_p4;
    sc_signal< bool > ap_block_pp1_stage0;
    sc_signal< sc_lv<64> > zext_ln58_fu_266_p1;
    sc_signal< sc_lv<64> > zext_ln99_fu_379_p1;
    sc_signal< sc_logic > ap_CS_fsm_state1;
    sc_signal< sc_lv<32> > acc_left_V_fu_245_p0;
    sc_signal< sc_lv<32> > sext_ln700_2_fu_276_p0;
    sc_signal< sc_lv<16> > mul_ln700_fu_284_p0;
    sc_signal< sc_lv<32> > mul_ln700_fu_284_p1;
    sc_signal< sc_lv<53> > sext_ln700_4_fu_290_p1;
    sc_signal< sc_lv<1> > tmp_2_fu_299_p3;
    sc_signal< sc_lv<32> > datain_left_V_fu_307_p2;
    sc_signal< sc_lv<32> > mul_ln700_1_fu_324_p1;
    sc_signal< sc_lv<47> > trunc_ln51_fu_330_p1;
    sc_signal< sc_lv<47> > sext_ln700_1_fu_334_p1;
    sc_signal< sc_lv<47> > acc_left_V_1_fu_337_p2;
    sc_signal< sc_lv<32> > acc_right_V_fu_358_p1;
    sc_signal< sc_lv<32> > sext_ln700_7_fu_389_p0;
    sc_signal< sc_lv<16> > mul_ln700_2_fu_397_p0;
    sc_signal< sc_lv<32> > mul_ln700_2_fu_397_p1;
    sc_signal< sc_lv<53> > sext_ln700_9_fu_403_p1;
    sc_signal< sc_lv<1> > tmp_3_fu_412_p3;
    sc_signal< sc_lv<32> > datain_right_V_fu_420_p2;
    sc_signal< sc_lv<32> > mul_ln700_3_fu_437_p1;
    sc_signal< sc_lv<47> > trunc_ln98_fu_443_p1;
    sc_signal< sc_lv<47> > sext_ln700_6_fu_447_p1;
    sc_signal< sc_lv<47> > acc_right_V_1_fu_450_p2;
    sc_signal< sc_lv<14> > ap_NS_fsm;
    sc_signal< sc_logic > regslice_both_dataout_data_V_U_apdone_blk;
    sc_signal< sc_logic > ap_idle_pp0;
    sc_signal< sc_logic > ap_enable_pp0;
    sc_signal< sc_logic > ap_idle_pp1;
    sc_signal< sc_logic > ap_enable_pp1;
    sc_signal< sc_logic > regslice_both_datain_data_V_U_apdone_blk;
    sc_signal< sc_lv<32> > datain_TDATA_int;
    sc_signal< sc_logic > datain_TVALID_int;
    sc_signal< sc_logic > datain_TREADY_int;
    sc_signal< sc_logic > regslice_both_datain_data_V_U_ack_in;
    sc_signal< sc_logic > regslice_both_datain_last_V_U_apdone_blk;
    sc_signal< sc_lv<1> > datain_TLAST_int;
    sc_signal< sc_logic > regslice_both_datain_last_V_U_vld_out;
    sc_signal< sc_logic > regslice_both_datain_last_V_U_ack_in;
    sc_signal< sc_lv<32> > dataout_TDATA_int;
    sc_signal< sc_logic > dataout_TVALID_int;
    sc_signal< sc_logic > dataout_TREADY_int;
    sc_signal< sc_logic > regslice_both_dataout_data_V_U_vld_out;
    sc_signal< sc_logic > regslice_both_dataout_last_V_U_apdone_blk;
    sc_signal< sc_lv<1> > dataout_TLAST_int;
    sc_signal< sc_logic > regslice_both_dataout_last_V_U_ack_in_dummy;
    sc_signal< sc_logic > regslice_both_dataout_last_V_U_vld_out;
    static const sc_logic ap_const_logic_1;
    static const sc_logic ap_const_logic_0;
    static const sc_lv<14> ap_ST_fsm_state1;
    static const sc_lv<14> ap_ST_fsm_state2;
    static const sc_lv<14> ap_ST_fsm_state3;
    static const sc_lv<14> ap_ST_fsm_state4;
    static const sc_lv<14> ap_ST_fsm_pp0_stage0;
    static const sc_lv<14> ap_ST_fsm_state9;
    static const sc_lv<14> ap_ST_fsm_state10;
    static const sc_lv<14> ap_ST_fsm_state11;
    static const sc_lv<14> ap_ST_fsm_state12;
    static const sc_lv<14> ap_ST_fsm_pp1_stage0;
    static const sc_lv<14> ap_ST_fsm_state17;
    static const sc_lv<14> ap_ST_fsm_state18;
    static const sc_lv<14> ap_ST_fsm_state19;
    static const sc_lv<14> ap_ST_fsm_state20;
    static const bool ap_const_boolean_1;
    static const sc_lv<32> ap_const_lv32_5;
    static const sc_lv<32> ap_const_lv32_A;
    static const sc_lv<32> ap_const_lv32_7;
    static const sc_lv<32> ap_const_lv32_8;
    static const sc_lv<32> ap_const_lv32_C;
    static const sc_lv<32> ap_const_lv32_D;
    static const sc_lv<32> ap_const_lv32_1;
    static const sc_lv<32> ap_const_lv32_4;
    static const bool ap_const_boolean_0;
    static const sc_lv<1> ap_const_lv1_0;
    static const sc_lv<32> ap_const_lv32_9;
    static const sc_lv<32> ap_const_lv32_6;
    static const sc_lv<32> ap_const_lv32_2;
    static const sc_lv<32> ap_const_lv32_3;
    static const sc_lv<32> ap_const_lv32_B;
    static const sc_lv<1> ap_const_lv1_1;
    static const sc_lv<6> ap_const_lv6_39;
    static const sc_lv<32> ap_const_lv32_0;
    static const sc_lv<6> ap_const_lv6_0;
    static const sc_lv<42> ap_const_lv42_3FFFFFFFE86;
    static const sc_lv<6> ap_const_lv6_3F;
    static const sc_lv<32> ap_const_lv32_F;
    static const sc_lv<32> ap_const_lv32_FFFF0000;
    static const sc_lv<32> ap_const_lv32_2E;
    // Thread declarations
    void thread_ap_clk_no_reset_();
    void thread_acc_left_V_1_fu_337_p2();
    void thread_acc_left_V_2_fu_293_p2();
    void thread_acc_left_V_fu_245_p0();
    void thread_acc_left_V_fu_245_p2();
    void thread_acc_right_V_1_fu_450_p2();
    void thread_acc_right_V_2_fu_406_p2();
    void thread_acc_right_V_fu_358_p1();
    void thread_acc_right_V_fu_358_p2();
    void thread_ap_CS_fsm_pp0_stage0();
    void thread_ap_CS_fsm_pp1_stage0();
    void thread_ap_CS_fsm_state1();
    void thread_ap_CS_fsm_state10();
    void thread_ap_CS_fsm_state11();
    void thread_ap_CS_fsm_state12();
    void thread_ap_CS_fsm_state17();
    void thread_ap_CS_fsm_state18();
    void thread_ap_CS_fsm_state19();
    void thread_ap_CS_fsm_state2();
    void thread_ap_CS_fsm_state20();
    void thread_ap_CS_fsm_state3();
    void thread_ap_CS_fsm_state4();
    void thread_ap_CS_fsm_state9();
    void thread_ap_block_pp0_stage0();
    void thread_ap_block_pp0_stage0_11001();
    void thread_ap_block_pp0_stage0_subdone();
    void thread_ap_block_pp1_stage0();
    void thread_ap_block_pp1_stage0_11001();
    void thread_ap_block_pp1_stage0_subdone();
    void thread_ap_block_state13_pp1_stage0_iter0();
    void thread_ap_block_state14_pp1_stage0_iter1();
    void thread_ap_block_state15_pp1_stage0_iter2();
    void thread_ap_block_state16_pp1_stage0_iter3();
    void thread_ap_block_state5_pp0_stage0_iter0();
    void thread_ap_block_state6_pp0_stage0_iter1();
    void thread_ap_block_state7_pp0_stage0_iter2();
    void thread_ap_block_state8_pp0_stage0_iter3();
    void thread_ap_condition_pp0_exit_iter0_state5();
    void thread_ap_condition_pp1_exit_iter0_state13();
    void thread_ap_enable_pp0();
    void thread_ap_enable_pp1();
    void thread_ap_idle_pp0();
    void thread_ap_idle_pp1();
    void thread_ap_phi_mux_i_0_phi_fu_193_p4();
    void thread_ap_phi_mux_i_1_phi_fu_214_p4();
    void thread_ap_rst_n_inv();
    void thread_c_address0();
    void thread_c_ce0();
    void thread_datain_TDATA_blk_n();
    void thread_datain_TREADY();
    void thread_datain_TREADY_int();
    void thread_datain_left_V_2_fu_313_p3();
    void thread_datain_left_V_fu_307_p2();
    void thread_datain_right_V_2_fu_426_p3();
    void thread_datain_right_V_fu_420_p2();
    void thread_dataout_TDATA_blk_n();
    void thread_dataout_TDATA_int();
    void thread_dataout_TLAST_int();
    void thread_dataout_TVALID();
    void thread_dataout_TVALID_int();
    void thread_i_2_fu_373_p2();
    void thread_i_fu_260_p2();
    void thread_icmp_ln51_fu_254_p2();
    void thread_icmp_ln98_fu_367_p2();
    void thread_mul_ln700_1_fu_324_p1();
    void thread_mul_ln700_1_fu_324_p2();
    void thread_mul_ln700_2_fu_397_p0();
    void thread_mul_ln700_2_fu_397_p1();
    void thread_mul_ln700_2_fu_397_p2();
    void thread_mul_ln700_3_fu_437_p1();
    void thread_mul_ln700_3_fu_437_p2();
    void thread_mul_ln700_fu_284_p0();
    void thread_mul_ln700_fu_284_p1();
    void thread_mul_ln700_fu_284_p2();
    void thread_sext_ln68_1_fu_251_p1();
    void thread_sext_ln68_3_fu_364_p1();
    void thread_sext_ln700_1_fu_334_p1();
    void thread_sext_ln700_2_fu_276_p0();
    void thread_sext_ln700_4_fu_290_p1();
    void thread_sext_ln700_6_fu_447_p1();
    void thread_sext_ln700_7_fu_389_p0();
    void thread_sext_ln700_9_fu_403_p1();
    void thread_shift_reg_left_V_address0();
    void thread_shift_reg_left_V_address1();
    void thread_shift_reg_left_V_ce0();
    void thread_shift_reg_left_V_ce1();
    void thread_shift_reg_left_V_d1();
    void thread_shift_reg_left_V_we1();
    void thread_shift_reg_right_V_address0();
    void thread_shift_reg_right_V_address1();
    void thread_shift_reg_right_V_ce0();
    void thread_shift_reg_right_V_ce1();
    void thread_shift_reg_right_V_d1();
    void thread_shift_reg_right_V_we1();
    void thread_tmp_2_fu_299_p3();
    void thread_tmp_3_fu_412_p3();
    void thread_trunc_ln51_fu_330_p1();
    void thread_trunc_ln98_fu_443_p1();
    void thread_zext_ln58_1_fu_271_p1();
    void thread_zext_ln58_fu_266_p1();
    void thread_zext_ln99_1_fu_384_p1();
    void thread_zext_ln99_fu_379_p1();
    void thread_ap_NS_fsm();
    void thread_hdltv_gen();
};

}

using namespace ap_rtl;

#endif