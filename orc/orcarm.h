
#ifndef _ORC_ARM_H_
#define _ORC_ARM_H_

#include <orc/orcprogram.h>

#define ORC_ARM_R0 (ORC_GP_REG_BASE+0)

#define ORC_ARM_A1 (ORC_GP_REG_BASE+0)
#define ORC_ARM_A2 (ORC_GP_REG_BASE+1)
#define ORC_ARM_A3 (ORC_GP_REG_BASE+2)
#define ORC_ARM_A4 (ORC_GP_REG_BASE+3)
#define ORC_ARM_V1 (ORC_GP_REG_BASE+4)
#define ORC_ARM_V2 (ORC_GP_REG_BASE+5)
#define ORC_ARM_V3 (ORC_GP_REG_BASE+6)
#define ORC_ARM_V4 (ORC_GP_REG_BASE+7)
#define ORC_ARM_V5 (ORC_GP_REG_BASE+8)
#define ORC_ARM_V6 (ORC_GP_REG_BASE+9)
#define ORC_ARM_V7 (ORC_GP_REG_BASE+10)
#define ORC_ARM_V8 (ORC_GP_REG_BASE+11)
#define ORC_ARM_IP (ORC_GP_REG_BASE+12)
#define ORC_ARM_SP (ORC_GP_REG_BASE+13)
#define ORC_ARM_LR (ORC_GP_REG_BASE+14)
#define ORC_ARM_PC (ORC_GP_REG_BASE+15)

#define ORC_ARM_SB (ORC_GP_REG_BASE+9)

enum {
  ORC_ARM_DP_AND = 0,
  ORC_ARM_DP_EOR,
  ORC_ARM_DP_SUB,
  ORC_ARM_DP_RSB,
  ORC_ARM_DP_ADD,
  ORC_ARM_DP_ADC,
  ORC_ARM_DP_SBC,
  ORC_ARM_DP_RSC,
  ORC_ARM_DP_TST,
  ORC_ARM_DP_TEQ,
  ORC_ARM_DP_CMP,
  ORC_ARM_DP_CMN,
  ORC_ARM_DP_ORR,
  ORC_ARM_DP_MOV,
  ORC_ARM_DP_BIC,
  ORC_ARM_DP_MVN
};

enum {
  ORC_ARM_COND_EQ = 0,
  ORC_ARM_COND_NE,
  ORC_ARM_COND_CS,
  ORC_ARM_COND_CC,
  ORC_ARM_COND_MI,
  ORC_ARM_COND_PL,
  ORC_ARM_COND_VS,
  ORC_ARM_COND_VC,
  ORC_ARM_COND_HI,
  ORC_ARM_COND_LS,
  ORC_ARM_COND_GE,
  ORC_ARM_COND_LT,
  ORC_ARM_COND_GT,
  ORC_ARM_COND_LE,
  ORC_ARM_COND_AL,
};

void orc_arm_emit (OrcCompiler *compiler, uint32_t insn);
void orc_arm_emit_bx_lr (OrcCompiler *compiler);
const char * orc_arm_reg_name (int reg);
void orc_arm_emit_loadimm (OrcCompiler *compiler, int dest, int imm);

void orc_arm_emit_add (OrcCompiler *compiler, int dest, int src1, int src2);
void orc_arm_emit_sub (OrcCompiler *compiler, int dest, int src1, int src2);
void orc_arm_emit_add_imm (OrcCompiler *compiler, int dest, int src1, int value);
void orc_arm_emit_sub_imm (OrcCompiler *compiler, int dest, int src1, int value);
void orc_arm_emit_cmp_imm (OrcCompiler *compiler, int src1, int value);

void orc_arm_emit_label (OrcCompiler *compiler, int label);
void orc_arm_emit_push (OrcCompiler *compiler, int regs);
void orc_arm_emit_pop (OrcCompiler *compiler, int regs);
void orc_arm_emit_mov (OrcCompiler *compiler, int dest, int src);
void orc_arm_emit_branch (OrcCompiler *compiler, int cond, int label);

void orc_arm_emit_dp_reg (OrcCompiler *compiler, int cond, int opcode, int dest,
    int src1, int src2);

void orc_arm_loadw (OrcCompiler *compiler, int dest, int src1, int offset);
void orc_arm_storew (OrcCompiler *compiler, int dest, int offset, int src1);

void orc_arm_emit_load_reg (OrcCompiler *compiler, int dest, int src1, int offset);

void orc_arm_do_fixups (OrcCompiler *compiler);


#endif
