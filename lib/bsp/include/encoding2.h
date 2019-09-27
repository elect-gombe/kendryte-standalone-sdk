/* Copyright 2018 Canaan Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

/*
 * encoding2.h as original file as it is for asm
 *
 */
#ifndef RISCV_CSR_ENCODING_H
#define RISCV_CSR_ENCODING_H

#define MSTATUS_UIE         0x00000001U
#define MSTATUS_SIE         0x00000002U
#define MSTATUS_HIE         0x00000004U
#define MSTATUS_MIE         0x00000008U
#define MSTATUS_UPIE        0x00000010U
#define MSTATUS_SPIE        0x00000020U
#define MSTATUS_HPIE        0x00000040U
#define MSTATUS_MPIE        0x00000080U
#define MSTATUS_SPP         0x00000100U
#define MSTATUS_HPP         0x00000600U
#define MSTATUS_MPP         0x00001800U
#define MSTATUS_FS          0x00006000U
#define MSTATUS_XS          0x00018000U
#define MSTATUS_MPRV        0x00020000U
#define MSTATUS_PUM         0x00040000U
#define MSTATUS_MXR         0x00080000U
#define MSTATUS_VM          0x1F000000U
#define MSTATUS32_SD        0x80000000U
#define MSTATUS64_SD        0x8000000000000000U

#define SSTATUS_UIE         0x00000001U
#define SSTATUS_SIE         0x00000002U
#define SSTATUS_UPIE        0x00000010U
#define SSTATUS_SPIE        0x00000020U
#define SSTATUS_SPP         0x00000100U
#define SSTATUS_FS          0x00006000U
#define SSTATUS_XS          0x00018000U
#define SSTATUS_PUM         0x00040000U
#define SSTATUS32_SD        0x80000000U
#define SSTATUS64_SD        0x8000000000000000U

#define DCSR_XDEBUGVER      (3U<<30)
#define DCSR_NDRESET        (1U<<29)
#define DCSR_FULLRESET      (1U<<28)
#define DCSR_EBREAKM        (1U<<15)
#define DCSR_EBREAKH        (1U<<14)
#define DCSR_EBREAKS        (1U<<13)
#define DCSR_EBREAKU        (1U<<12)
#define DCSR_STOPCYCLE      (1U<<10)
#define DCSR_STOPTIME       (1U<<9)
#define DCSR_CAUSE          (7U<<6)
#define DCSR_DEBUGINT       (1U<<5)
#define DCSR_HALT           (1U<<3)
#define DCSR_STEP           (1U<<2)
#define DCSR_PRV            (3U<<0)

#define DCSR_CAUSE_NONE     0
#define DCSR_CAUSE_SWBP     1
#define DCSR_CAUSE_HWBP     2
#define DCSR_CAUSE_DEBUGINT 3
#define DCSR_CAUSE_STEP     4
#define DCSR_CAUSE_HALT     5

#define MCONTROL_SELECT     (1U<<19)
#define MCONTROL_TIMING     (1U<<18)
#define MCONTROL_ACTION     (0x3fU<<12)
#define MCONTROL_CHAIN      (1U<<11)
#define MCONTROL_MATCH      (0xfU<<7)
#define MCONTROL_M          (1U<<6)
#define MCONTROL_H          (1U<<5)
#define MCONTROL_S          (1U<<4)
#define MCONTROL_U          (1U<<3)
#define MCONTROL_EXECUTE    (1U<<2)
#define MCONTROL_STORE      (1U<<1)
#define MCONTROL_LOAD       (1U<<0)

#define MCONTROL_TYPE_NONE      0
#define MCONTROL_TYPE_MATCH     2

#define MCONTROL_ACTION_DEBUG_EXCEPTION   0
#define MCONTROL_ACTION_DEBUG_MODE        1
#define MCONTROL_ACTION_TRACE_START       2
#define MCONTROL_ACTION_TRACE_STOP        3
#define MCONTROL_ACTION_TRACE_EMIT        4

#define MCONTROL_MATCH_EQUAL     0
#define MCONTROL_MATCH_NAPOT     1
#define MCONTROL_MATCH_GE        2
#define MCONTROL_MATCH_LT        3
#define MCONTROL_MATCH_MASK_LOW  4
#define MCONTROL_MATCH_MASK_HIGH 5

#define MIP_SSIP            (1U << IRQ_S_SOFT)
#define MIP_HSIP            (1U << IRQ_H_SOFT)
#define MIP_MSIP            (1U << IRQ_M_SOFT)
#define MIP_STIP            (1U << IRQ_S_TIMER)
#define MIP_HTIP            (1U << IRQ_H_TIMER)
#define MIP_MTIP            (1U << IRQ_M_TIMER)
#define MIP_SEIP            (1U << IRQ_S_EXT)
#define MIP_HEIP            (1U << IRQ_H_EXT)
#define MIP_MEIP            (1U << IRQ_M_EXT)

#define SIP_SSIP MIP_SSIP
#define SIP_STIP MIP_STIP

#define PRV_U 0
#define PRV_S 1
#define PRV_H 2
#define PRV_M 3

#define VM_MBARE 0
#define VM_MBB   1
#define VM_MBBID 2
#define VM_SV32  8
#define VM_SV39  9
#define VM_SV48  10

#define IRQ_S_SOFT   1
#define IRQ_H_SOFT   2
#define IRQ_M_SOFT   3
#define IRQ_S_TIMER  5
#define IRQ_H_TIMER  6
#define IRQ_M_TIMER  7
#define IRQ_S_EXT    9
#define IRQ_H_EXT    10
#define IRQ_M_EXT    11
#define IRQ_COP      12
#define IRQ_HOST     13

#define DEFAULT_RSTVEC     0x00001000U
#define DEFAULT_NMIVEC     0x00001004U
#define DEFAULT_MTVEC      0x00001010U
#define CONFIG_STRING_ADDR 0x0000100CU
#define EXT_IO_BASE        0x40000000U
#define DRAM_BASE          0x80000000U

/* page table entry (PTE) fields */
#define PTE_V     0x001U /* Valid */
#define PTE_R     0x002U /* Read */
#define PTE_W     0x004U /* Write */
#define PTE_X     0x008U /* Execute */
#define PTE_U     0x010U /* User */
#define PTE_G     0x020U /* Global */
#define PTE_A     0x040U /* Accessed */
#define PTE_D     0x080U /* Dirty */
#define PTE_SOFT  0x300U /* Reserved for Software */

#define PTE_PPN_SHIFT 10

#define MCONTROL_TYPE(xlen)    (0xfULL<<((xlen)-4))
#define MCONTROL_DMODE(xlen)   (1ULL<<((xlen)-5))
#define MCONTROL_MASKMAX(xlen) (0x3fULL<<((xlen)-11))

#define PTE_TABLE(PTE) (((PTE) & (PTE_V | PTE_R | PTE_W | PTE_X)) == PTE_V)

#if defined(__riscv)

#if defined(__riscv64)
# define MSTATUS_SD MSTATUS64_SD
# define SSTATUS_SD SSTATUS64_SD
# define RISCV_PGLEVEL_BITS 9
#else
# define MSTATUS_SD MSTATUS32_SD
# define SSTATUS_SD SSTATUS32_SD
# define RISCV_PGLEVEL_BITS 10
#endif
#define RISCV_PGSHIFT 12
#define RISCV_PGSIZE (1 << RISCV_PGSHIFT)

#ifndef __ASSEMBLER__

#if defined(__GNUC__)

#define read_csr(reg) ({ unsigned long __tmp; \
  asm volatile ("csrr %0, " #reg : "=r"(__tmp)); \
  __tmp; })

#define write_csr(reg, val) ({ \
  if (__builtin_constant_p(val) && (unsigned long)(val) < 32) \
    asm volatile ("csrw " #reg ", %0" :: "i"(val)); \
  else \
    asm volatile ("csrw " #reg ", %0" :: "r"(val)); })

#define swap_csr(reg, val) ({ unsigned long __tmp; \
  if (__builtin_constant_p(val) && (unsigned long)(val) < 32) \
    asm volatile ("csrrw %0, " #reg ", %1" : "=r"(__tmp) : "i"(val)); \
  else \
    asm volatile ("csrrw %0, " #reg ", %1" : "=r"(__tmp) : "r"(val)); \
  __tmp; })

#define set_csr(reg, bit) ({ unsigned long __tmp; \
  if (__builtin_constant_p(bit) && (unsigned long)(bit) < 32) \
    asm volatile ("csrrs %0, " #reg ", %1" : "=r"(__tmp) : "i"(bit)); \
  else \
    asm volatile ("csrrs %0, " #reg ", %1" : "=r"(__tmp) : "r"(bit)); \
  __tmp; })

#define clear_csr(reg, bit) ({ unsigned long __tmp; \
  if (__builtin_constant_p(bit) && (unsigned long)(bit) < 32) \
    asm volatile ("csrrc %0, " #reg ", %1" : "=r"(__tmp) : "i"(bit)); \
  else \
    asm volatile ("csrrc %0, " #reg ", %1" : "=r"(__tmp) : "r"(bit)); \
  __tmp; })

//#define read_time()         read_csr(mtime) unused?
#define read_cycle()        get_cycle()
#define current_coreid()       get_hartid()

#endif

#endif

#endif

#endif

#ifndef RISCV_ENCODING_H
#define RISCV_ENCODING_H
#define MATCH_BEQ                  0x63U
#define MASK_BEQ                   0x707fU
#define MATCH_BNE                  0x1063U
#define MASK_BNE                   0x707fU
#define MATCH_BLT                  0x4063U
#define MASK_BLT                   0x707fU
#define MATCH_BGE                  0x5063U
#define MASK_BGE                   0x707fU
#define MATCH_BLTU                 0x6063U
#define MASK_BLTU                  0x707fU
#define MATCH_BGEU                 0x7063U
#define MASK_BGEU                  0x707fU
#define MATCH_JALR                 0x67U
#define MASK_JALR                  0x707fU
#define MATCH_JAL                  0x6fU
#define MASK_JAL                   0x7fU
#define MATCH_LUI                  0x37U
#define MASK_LUI                   0x7fU
#define MATCH_AUIPC                0x17U
#define MASK_AUIPC                 0x7fU
#define MATCH_ADDI                 0x13U
#define MASK_ADDI                  0x707fU
#define MATCH_SLLI                 0x1013U
#define MASK_SLLI                  0xfc00707fU
#define MATCH_SLTI                 0x2013U
#define MASK_SLTI                  0x707fU
#define MATCH_SLTIU                0x3013U
#define MASK_SLTIU                 0x707fU
#define MATCH_XORI                 0x4013U
#define MASK_XORI                  0x707fU
#define MATCH_SRLI                 0x5013U
#define MASK_SRLI                  0xfc00707fU
#define MATCH_SRAI                 0x40005013U
#define MASK_SRAI                  0xfc00707fU
#define MATCH_ORI                  0x6013U
#define MASK_ORI                   0x707fU
#define MATCH_ANDI                 0x7013U
#define MASK_ANDI                  0x707fU
#define MATCH_ADD                  0x33U
#define MASK_ADD                   0xfe00707fU
#define MATCH_SUB                  0x40000033U
#define MASK_SUB                   0xfe00707fU
#define MATCH_SLL                  0x1033U
#define MASK_SLL                   0xfe00707fU
#define MATCH_SLT                  0x2033U
#define MASK_SLT                   0xfe00707fU
#define MATCH_SLTU                 0x3033U
#define MASK_SLTU                  0xfe00707fU
#define MATCH_XOR                  0x4033U
#define MASK_XOR                   0xfe00707fU
#define MATCH_SRL                  0x5033U
#define MASK_SRL                   0xfe00707fU
#define MATCH_SRA                  0x40005033U
#define MASK_SRA                   0xfe00707fU
#define MATCH_OR                   0x6033U
#define MASK_OR                    0xfe00707fU
#define MATCH_AND                  0x7033U
#define MASK_AND                   0xfe00707fU
#define MATCH_ADDIW                0x1bU
#define MASK_ADDIW                 0x707fU
#define MATCH_SLLIW                0x101bU
#define MASK_SLLIW                 0xfe00707fU
#define MATCH_SRLIW                0x501bU
#define MASK_SRLIW                 0xfe00707fU
#define MATCH_SRAIW                0x4000501bU
#define MASK_SRAIW                 0xfe00707fU
#define MATCH_ADDW                 0x3bU
#define MASK_ADDW                  0xfe00707fU
#define MATCH_SUBW                 0x4000003bU
#define MASK_SUBW                  0xfe00707fU
#define MATCH_SLLW                 0x103bU
#define MASK_SLLW                  0xfe00707fU
#define MATCH_SRLW                 0x503bU
#define MASK_SRLW                  0xfe00707fU
#define MATCH_SRAW                 0x4000503bU
#define MASK_SRAW                  0xfe00707fU
#define MATCH_LB                   0x3U
#define MASK_LB                    0x707fU
#define MATCH_LH                   0x1003U
#define MASK_LH                    0x707fU
#define MATCH_LW                   0x2003U
#define MASK_LW                    0x707fU
#define MATCH_LD                   0x3003U
#define MASK_LD                    0x707fU
#define MATCH_LBU                  0x4003U
#define MASK_LBU                   0x707fU
#define MATCH_LHU                  0x5003U
#define MASK_LHU                   0x707fU
#define MATCH_LWU                  0x6003U
#define MASK_LWU                   0x707fU
#define MATCH_SB                   0x23U
#define MASK_SB                    0x707fU
#define MATCH_SH                   0x1023U
#define MASK_SH                    0x707fU
#define MATCH_SW                   0x2023U
#define MASK_SW                    0x707fU
#define MATCH_SD                   0x3023U
#define MASK_SD                    0x707fU
#define MATCH_FENCE                0xfU
#define MASK_FENCE                 0x707fU
#define MATCH_FENCE_I              0x100fU
#define MASK_FENCE_I               0x707fU
#define MATCH_MUL                  0x2000033U
#define MASK_MUL                   0xfe00707fU
#define MATCH_MULH                 0x2001033U
#define MASK_MULH                  0xfe00707fU
#define MATCH_MULHSU               0x2002033U
#define MASK_MULHSU                0xfe00707fU
#define MATCH_MULHU                0x2003033U
#define MASK_MULHU                 0xfe00707fU
#define MATCH_DIV                  0x2004033U
#define MASK_DIV                   0xfe00707fU
#define MATCH_DIVU                 0x2005033U
#define MASK_DIVU                  0xfe00707fU
#define MATCH_REM                  0x2006033U
#define MASK_REM                   0xfe00707fU
#define MATCH_REMU                 0x2007033U
#define MASK_REMU                  0xfe00707fU
#define MATCH_MULW                 0x200003bU
#define MASK_MULW                  0xfe00707fU
#define MATCH_DIVW                 0x200403bU
#define MASK_DIVW                  0xfe00707fU
#define MATCH_DIVUW                0x200503bU
#define MASK_DIVUW                 0xfe00707fU
#define MATCH_REMW                 0x200603bU
#define MASK_REMW                  0xfe00707fU
#define MATCH_REMUW                0x200703bU
#define MASK_REMUW                 0xfe00707fU
#define MATCH_AMOADD_W             0x202fU
#define MASK_AMOADD_W              0xf800707fU
#define MATCH_AMOXOR_W             0x2000202fU
#define MASK_AMOXOR_W              0xf800707fU
#define MATCH_AMOOR_W              0x4000202fU
#define MASK_AMOOR_W               0xf800707fU
#define MATCH_AMOAND_W             0x6000202fU
#define MASK_AMOAND_W              0xf800707fU
#define MATCH_AMOMIN_W             0x8000202fU
#define MASK_AMOMIN_W              0xf800707fU
#define MATCH_AMOMAX_W             0xa000202fU
#define MASK_AMOMAX_W              0xf800707fU
#define MATCH_AMOMINU_W            0xc000202fU
#define MASK_AMOMINU_W             0xf800707fU
#define MATCH_AMOMAXU_W            0xe000202fU
#define MASK_AMOMAXU_W             0xf800707fU
#define MATCH_AMOSWAP_W            0x800202fU
#define MASK_AMOSWAP_W             0xf800707fU
#define MATCH_LR_W                 0x1000202fU
#define MASK_LR_W                  0xf9f0707fU
#define MATCH_SC_W                 0x1800202fU
#define MASK_SC_W                  0xf800707fU
#define MATCH_AMOADD_D             0x302fU
#define MASK_AMOADD_D              0xf800707fU
#define MATCH_AMOXOR_D             0x2000302fU
#define MASK_AMOXOR_D              0xf800707fU
#define MATCH_AMOOR_D              0x4000302fU
#define MASK_AMOOR_D               0xf800707fU
#define MATCH_AMOAND_D             0x6000302fU
#define MASK_AMOAND_D              0xf800707fU
#define MATCH_AMOMIN_D             0x8000302fU
#define MASK_AMOMIN_D              0xf800707fU
#define MATCH_AMOMAX_D             0xa000302fU
#define MASK_AMOMAX_D              0xf800707fU
#define MATCH_AMOMINU_D            0xc000302fU
#define MASK_AMOMINU_D             0xf800707fU
#define MATCH_AMOMAXU_D            0xe000302fU
#define MASK_AMOMAXU_D             0xf800707fU
#define MATCH_AMOSWAP_D            0x800302fU
#define MASK_AMOSWAP_D             0xf800707fU
#define MATCH_LR_D                 0x1000302fU
#define MASK_LR_D                  0xf9f0707fU
#define MATCH_SC_D                 0x1800302fU
#define MASK_SC_D                  0xf800707fU
#define MATCH_ECALL                0x73U
#define MASK_ECALL                 0xffffffffU
#define MATCH_EBREAK               0x100073U
#define MASK_EBREAK                0xffffffffU
#define MATCH_URET                 0x200073U
#define MASK_URET                  0xffffffffU
#define MATCH_SRET                 0x10200073U
#define MASK_SRET                  0xffffffffU
#define MATCH_HRET                 0x20200073U
#define MASK_HRET                  0xffffffffU
#define MATCH_MRET                 0x30200073U
#define MASK_MRET                  0xffffffffU
#define MATCH_DRET                 0x7b200073U
#define MASK_DRET                  0xffffffffU
#define MATCH_SFENCE_VM            0x10400073U
#define MASK_SFENCE_VM             0xfff07fffU
#define MATCH_WFI                  0x10500073U
#define MASK_WFI                   0xffffffffU
#define MATCH_CSRRW                0x1073U
#define MASK_CSRRW                 0x707fU
#define MATCH_CSRRS                0x2073U
#define MASK_CSRRS                 0x707fU
#define MATCH_CSRRC                0x3073U
#define MASK_CSRRC                 0x707fU
#define MATCH_CSRRWI               0x5073U
#define MASK_CSRRWI                0x707fU
#define MATCH_CSRRSI               0x6073U
#define MASK_CSRRSI                0x707fU
#define MATCH_CSRRCI               0x7073U
#define MASK_CSRRCI                0x707fU
#define MATCH_FADD_S               0x53U
#define MASK_FADD_S                0xfe00007fU
#define MATCH_FSUB_S               0x8000053U
#define MASK_FSUB_S                0xfe00007fU
#define MATCH_FMUL_S               0x10000053U
#define MASK_FMUL_S                0xfe00007fU
#define MATCH_FDIV_S               0x18000053U
#define MASK_FDIV_S                0xfe00007fU
#define MATCH_FSGNJ_S              0x20000053U
#define MASK_FSGNJ_S               0xfe00707fU
#define MATCH_FSGNJN_S             0x20001053U
#define MASK_FSGNJN_S              0xfe00707fU
#define MATCH_FSGNJX_S             0x20002053U
#define MASK_FSGNJX_S              0xfe00707fU
#define MATCH_FMIN_S               0x28000053U
#define MASK_FMIN_S                0xfe00707fU
#define MATCH_FMAX_S               0x28001053U
#define MASK_FMAX_S                0xfe00707fU
#define MATCH_FSQRT_S              0x58000053U
#define MASK_FSQRT_S               0xfff0007fU
#define MATCH_FADD_D               0x2000053U
#define MASK_FADD_D                0xfe00007fU
#define MATCH_FSUB_D               0xa000053U
#define MASK_FSUB_D                0xfe00007fU
#define MATCH_FMUL_D               0x12000053U
#define MASK_FMUL_D                0xfe00007fU
#define MATCH_FDIV_D               0x1a000053U
#define MASK_FDIV_D                0xfe00007fU
#define MATCH_FSGNJ_D              0x22000053U
#define MASK_FSGNJ_D               0xfe00707fU
#define MATCH_FSGNJN_D             0x22001053U
#define MASK_FSGNJN_D              0xfe00707fU
#define MATCH_FSGNJX_D             0x22002053U
#define MASK_FSGNJX_D              0xfe00707fU
#define MATCH_FMIN_D               0x2a000053U
#define MASK_FMIN_D                0xfe00707fU
#define MATCH_FMAX_D               0x2a001053U
#define MASK_FMAX_D                0xfe00707fU
#define MATCH_FCVT_S_D             0x40100053U
#define MASK_FCVT_S_D              0xfff0007fU
#define MATCH_FCVT_D_S             0x42000053U
#define MASK_FCVT_D_S              0xfff0007fU
#define MATCH_FSQRT_D              0x5a000053U
#define MASK_FSQRT_D               0xfff0007fU
#define MATCH_FLE_S                0xa0000053U
#define MASK_FLE_S                 0xfe00707fU
#define MATCH_FLT_S                0xa0001053U
#define MASK_FLT_S                 0xfe00707fU
#define MATCH_FEQ_S                0xa0002053U
#define MASK_FEQ_S                 0xfe00707fU
#define MATCH_FLE_D                0xa2000053U
#define MASK_FLE_D                 0xfe00707fU
#define MATCH_FLT_D                0xa2001053U
#define MASK_FLT_D                 0xfe00707fU
#define MATCH_FEQ_D                0xa2002053U
#define MASK_FEQ_D                 0xfe00707fU
#define MATCH_FCVT_W_S             0xc0000053U
#define MASK_FCVT_W_S              0xfff0007fU
#define MATCH_FCVT_WU_S            0xc0100053U
#define MASK_FCVT_WU_S             0xfff0007fU
#define MATCH_FCVT_L_S             0xc0200053U
#define MASK_FCVT_L_S              0xfff0007fU
#define MATCH_FCVT_LU_S            0xc0300053U
#define MASK_FCVT_LU_S             0xfff0007fU
#define MATCH_FMV_X_S              0xe0000053U
#define MASK_FMV_X_S               0xfff0707fU
#define MATCH_FCLASS_S             0xe0001053U
#define MASK_FCLASS_S              0xfff0707fU
#define MATCH_FCVT_W_D             0xc2000053U
#define MASK_FCVT_W_D              0xfff0007fU
#define MATCH_FCVT_WU_D            0xc2100053U
#define MASK_FCVT_WU_D             0xfff0007fU
#define MATCH_FCVT_L_D             0xc2200053U
#define MASK_FCVT_L_D              0xfff0007fU
#define MATCH_FCVT_LU_D            0xc2300053U
#define MASK_FCVT_LU_D             0xfff0007fU
#define MATCH_FMV_X_D              0xe2000053U
#define MASK_FMV_X_D               0xfff0707fU
#define MATCH_FCLASS_D             0xe2001053U
#define MASK_FCLASS_D              0xfff0707fU
#define MATCH_FCVT_S_W             0xd0000053U
#define MASK_FCVT_S_W              0xfff0007fU
#define MATCH_FCVT_S_WU            0xd0100053U
#define MASK_FCVT_S_WU             0xfff0007fU
#define MATCH_FCVT_S_L             0xd0200053U
#define MASK_FCVT_S_L              0xfff0007fU
#define MATCH_FCVT_S_LU            0xd0300053U
#define MASK_FCVT_S_LU             0xfff0007fU
#define MATCH_FMV_S_X              0xf0000053U
#define MASK_FMV_S_X               0xfff0707fU
#define MATCH_FCVT_D_W             0xd2000053U
#define MASK_FCVT_D_W              0xfff0007fU
#define MATCH_FCVT_D_WU            0xd2100053U
#define MASK_FCVT_D_WU             0xfff0007fU
#define MATCH_FCVT_D_L             0xd2200053U
#define MASK_FCVT_D_L              0xfff0007fU
#define MATCH_FCVT_D_LU            0xd2300053U
#define MASK_FCVT_D_LU             0xfff0007fU
#define MATCH_FMV_D_X              0xf2000053U
#define MASK_FMV_D_X               0xfff0707fU
#define MATCH_FLW                  0x2007U
#define MASK_FLW                   0x707fU
#define MATCH_FLD                  0x3007U
#define MASK_FLD                   0x707fU
#define MATCH_FSW                  0x2027U
#define MASK_FSW                   0x707fU
#define MATCH_FSD                  0x3027U
#define MASK_FSD                   0x707fU
#define MATCH_FMADD_S              0x43U
#define MASK_FMADD_S               0x600007fU
#define MATCH_FMSUB_S              0x47U
#define MASK_FMSUB_S               0x600007fU
#define MATCH_FNMSUB_S             0x4bU
#define MASK_FNMSUB_S              0x600007fU
#define MATCH_FNMADD_S             0x4fU
#define MASK_FNMADD_S              0x600007fU
#define MATCH_FMADD_D              0x2000043U
#define MASK_FMADD_D               0x600007fU
#define MATCH_FMSUB_D              0x2000047U
#define MASK_FMSUB_D               0x600007fU
#define MATCH_FNMSUB_D             0x200004bU
#define MASK_FNMSUB_D              0x600007fU
#define MATCH_FNMADD_D             0x200004fU
#define MASK_FNMADD_D              0x600007fU
#define MATCH_C_NOP                0x1U
#define MASK_C_NOP                 0xffffU
#define MATCH_C_ADDI16SP           0x6101U
#define MASK_C_ADDI16SP            0xef83U
#define MATCH_C_JR                 0x8002U
#define MASK_C_JR                  0xf07fU
#define MATCH_C_JALR               0x9002U
#define MASK_C_JALR                0xf07fU
#define MATCH_C_EBREAK             0x9002U
#define MASK_C_EBREAK              0xffffU
#define MATCH_C_LD                 0x6000U
#define MASK_C_LD                  0xe003U
#define MATCH_C_SD                 0xe000U
#define MASK_C_SD                  0xe003U
#define MATCH_C_ADDIW              0x2001U
#define MASK_C_ADDIW               0xe003U
#define MATCH_C_LDSP               0x6002U
#define MASK_C_LDSP                0xe003U
#define MATCH_C_SDSP               0xe002U
#define MASK_C_SDSP                0xe003U
#define MATCH_C_ADDI4SPN           0x0U
#define MASK_C_ADDI4SPN            0xe003U
#define MATCH_C_FLD                0x2000U
#define MASK_C_FLD                 0xe003U
#define MATCH_C_LW                 0x4000U
#define MASK_C_LW                  0xe003U
#define MATCH_C_FLW                0x6000U
#define MASK_C_FLW                 0xe003U
#define MATCH_C_FSD                0xa000U
#define MASK_C_FSD                 0xe003U
#define MATCH_C_SW                 0xc000U
#define MASK_C_SW                  0xe003U
#define MATCH_C_FSW                0xe000U
#define MASK_C_FSW                 0xe003U
#define MATCH_C_ADDI               0x1U
#define MASK_C_ADDI                0xe003U
#define MATCH_C_JAL                0x2001U
#define MASK_C_JAL                 0xe003U
#define MATCH_C_LI                 0x4001U
#define MASK_C_LI                  0xe003U
#define MATCH_C_LUI                0x6001U
#define MASK_C_LUI                 0xe003U
#define MATCH_C_SRLI               0x8001U
#define MASK_C_SRLI                0xec03U
#define MATCH_C_SRAI               0x8401U
#define MASK_C_SRAI                0xec03U
#define MATCH_C_ANDI               0x8801U
#define MASK_C_ANDI                0xec03U
#define MATCH_C_SUB                0x8c01U
#define MASK_C_SUB                 0xfc63U
#define MATCH_C_XOR                0x8c21U
#define MASK_C_XOR                 0xfc63U
#define MATCH_C_OR                 0x8c41U
#define MASK_C_OR                  0xfc63U
#define MATCH_C_AND                0x8c61U
#define MASK_C_AND                 0xfc63U
#define MATCH_C_SUBW               0x9c01U
#define MASK_C_SUBW                0xfc63U
#define MATCH_C_ADDW               0x9c21U
#define MASK_C_ADDW                0xfc63U
#define MATCH_C_J                  0xa001U
#define MASK_C_J                   0xe003U
#define MATCH_C_BEQZ               0xc001U
#define MASK_C_BEQZ                0xe003U
#define MATCH_C_BNEZ               0xe001U
#define MASK_C_BNEZ                0xe003U
#define MATCH_C_SLLI               0x2U
#define MASK_C_SLLI                0xe003U
#define MATCH_C_FLDSP              0x2002U
#define MASK_C_FLDSP               0xe003U
#define MATCH_C_LWSP               0x4002U
#define MASK_C_LWSP                0xe003U
#define MATCH_C_FLWSP              0x6002U
#define MASK_C_FLWSP               0xe003U
#define MATCH_C_MV                 0x8002U
#define MASK_C_MV                  0xf003U
#define MATCH_C_ADD                0x9002U
#define MASK_C_ADD                 0xf003U
#define MATCH_C_FSDSP              0xa002U
#define MASK_C_FSDSP               0xe003U
#define MATCH_C_SWSP               0xc002U
#define MASK_C_SWSP                0xe003U
#define MATCH_C_FSWSP              0xe002U
#define MASK_C_FSWSP               0xe003U
#define MATCH_CUSTOM0              0xbU
#define MASK_CUSTOM0               0x707fU
#define MATCH_CUSTOM0_RS1          0x200bU
#define MASK_CUSTOM0_RS1           0x707fU
#define MATCH_CUSTOM0_RS1_RS2      0x300bU
#define MASK_CUSTOM0_RS1_RS2       0x707fU
#define MATCH_CUSTOM0_RD           0x400bU
#define MASK_CUSTOM0_RD            0x707fU
#define MATCH_CUSTOM0_RD_RS1       0x600bU
#define MASK_CUSTOM0_RD_RS1        0x707fU
#define MATCH_CUSTOM0_RD_RS1_RS2   0x700bU
#define MASK_CUSTOM0_RD_RS1_RS2    0x707fU
#define MATCH_CUSTOM1              0x2bU
#define MASK_CUSTOM1               0x707fU
#define MATCH_CUSTOM1_RS1          0x202bU
#define MASK_CUSTOM1_RS1           0x707fU
#define MATCH_CUSTOM1_RS1_RS2      0x302bU
#define MASK_CUSTOM1_RS1_RS2       0x707fU
#define MATCH_CUSTOM1_RD           0x402bU
#define MASK_CUSTOM1_RD            0x707fU
#define MATCH_CUSTOM1_RD_RS1       0x602bU
#define MASK_CUSTOM1_RD_RS1        0x707fU
#define MATCH_CUSTOM1_RD_RS1_RS2   0x702bU
#define MASK_CUSTOM1_RD_RS1_RS2    0x707fU
#define MATCH_CUSTOM2              0x5bU
#define MASK_CUSTOM2               0x707fU
#define MATCH_CUSTOM2_RS1          0x205bU
#define MASK_CUSTOM2_RS1           0x707fU
#define MATCH_CUSTOM2_RS1_RS2      0x305bU
#define MASK_CUSTOM2_RS1_RS2       0x707fU
#define MATCH_CUSTOM2_RD           0x405bU
#define MASK_CUSTOM2_RD            0x707fU
#define MATCH_CUSTOM2_RD_RS1       0x605bU
#define MASK_CUSTOM2_RD_RS1        0x707fU
#define MATCH_CUSTOM2_RD_RS1_RS2   0x705bU
#define MASK_CUSTOM2_RD_RS1_RS2    0x707fU
#define MATCH_CUSTOM3              0x7bU
#define MASK_CUSTOM3               0x707fU
#define MATCH_CUSTOM3_RS1          0x207bU
#define MASK_CUSTOM3_RS1           0x707fU
#define MATCH_CUSTOM3_RS1_RS2      0x307bU
#define MASK_CUSTOM3_RS1_RS2       0x707fU
#define MATCH_CUSTOM3_RD           0x407bU
#define MASK_CUSTOM3_RD            0x707fU
#define MATCH_CUSTOM3_RD_RS1       0x607bU
#define MASK_CUSTOM3_RD_RS1        0x707fU
#define MATCH_CUSTOM3_RD_RS1_RS2   0x707bU
#define MASK_CUSTOM3_RD_RS1_RS2    0x707fU
#define CSR_FFLAGS                 0x1U
#define CSR_FRM                    0x2U
#define CSR_FCSR                   0x3U
#define CSR_CYCLE                  0xc00U
#define CSR_TIME                   0xc01U
#define CSR_INSTRET                0xc02U
#define CSR_HPMCOUNTER3            0xc03U
#define CSR_HPMCOUNTER4            0xc04U
#define CSR_HPMCOUNTER5            0xc05U
#define CSR_HPMCOUNTER6            0xc06U
#define CSR_HPMCOUNTER7            0xc07U
#define CSR_HPMCOUNTER8            0xc08U
#define CSR_HPMCOUNTER9            0xc09U
#define CSR_HPMCOUNTER10           0xc0aU
#define CSR_HPMCOUNTER11           0xc0bU
#define CSR_HPMCOUNTER12           0xc0cU
#define CSR_HPMCOUNTER13           0xc0dU
#define CSR_HPMCOUNTER14           0xc0eU
#define CSR_HPMCOUNTER15           0xc0fU
#define CSR_HPMCOUNTER16           0xc10U
#define CSR_HPMCOUNTER17           0xc11U
#define CSR_HPMCOUNTER18           0xc12U
#define CSR_HPMCOUNTER19           0xc13U
#define CSR_HPMCOUNTER20           0xc14U
#define CSR_HPMCOUNTER21           0xc15U
#define CSR_HPMCOUNTER22           0xc16U
#define CSR_HPMCOUNTER23           0xc17U
#define CSR_HPMCOUNTER24           0xc18U
#define CSR_HPMCOUNTER25           0xc19U
#define CSR_HPMCOUNTER26           0xc1aU
#define CSR_HPMCOUNTER27           0xc1bU
#define CSR_HPMCOUNTER28           0xc1cU
#define CSR_HPMCOUNTER29           0xc1dU
#define CSR_HPMCOUNTER30           0xc1eU
#define CSR_HPMCOUNTER31           0xc1fU
#define CSR_SSTATUS                0x100U
#define CSR_SIE                    0x104U
#define CSR_STVEC                  0x105U
#define CSR_SSCRATCH               0x140U
#define CSR_SEPC                   0x141U
#define CSR_SCAUSE                 0x142U
#define CSR_SBADADDR               0x143U
#define CSR_SIP                    0x144U
#define CSR_SPTBR                  0x180U
#define CSR_MSTATUS                0x300U
#define CSR_MISA                   0x301U
#define CSR_MEDELEG                0x302U
#define CSR_MIDELEG                0x303U
#define CSR_MIE                    0x304U
#define CSR_MTVEC                  0x305U
#define CSR_MSCRATCH               0x340U
#define CSR_MEPC                   0x341U
#define CSR_MCAUSE                 0x342U
#define CSR_MBADADDR               0x343U
#define CSR_MIP                    0x344U
#define CSR_TSELECT                0x7a0U
#define CSR_TDATA1                 0x7a1U
#define CSR_TDATA2                 0x7a2U
#define CSR_TDATA3                 0x7a3U
#define CSR_DCSR                   0x7b0U
#define CSR_DPC                    0x7b1U
#define CSR_DSCRATCH               0x7b2U
#define CSR_MCYCLE                 0xb00U
#define CSR_MINSTRET               0xb02U
#define CSR_MHPMCOUNTER3           0xb03U
#define CSR_MHPMCOUNTER4           0xb04U
#define CSR_MHPMCOUNTER5           0xb05U
#define CSR_MHPMCOUNTER6           0xb06U
#define CSR_MHPMCOUNTER7           0xb07U
#define CSR_MHPMCOUNTER8           0xb08U
#define CSR_MHPMCOUNTER9           0xb09U
#define CSR_MHPMCOUNTER10          0xb0aU
#define CSR_MHPMCOUNTER11          0xb0bU
#define CSR_MHPMCOUNTER12          0xb0cU
#define CSR_MHPMCOUNTER13          0xb0dU
#define CSR_MHPMCOUNTER14          0xb0eU
#define CSR_MHPMCOUNTER15          0xb0fU
#define CSR_MHPMCOUNTER16          0xb10U
#define CSR_MHPMCOUNTER17          0xb11U
#define CSR_MHPMCOUNTER18          0xb12U
#define CSR_MHPMCOUNTER19          0xb13U
#define CSR_MHPMCOUNTER20          0xb14U
#define CSR_MHPMCOUNTER21          0xb15U
#define CSR_MHPMCOUNTER22          0xb16U
#define CSR_MHPMCOUNTER23          0xb17U
#define CSR_MHPMCOUNTER24          0xb18U
#define CSR_MHPMCOUNTER25          0xb19U
#define CSR_MHPMCOUNTER26          0xb1aU
#define CSR_MHPMCOUNTER27          0xb1bU
#define CSR_MHPMCOUNTER28          0xb1cU
#define CSR_MHPMCOUNTER29          0xb1dU
#define CSR_MHPMCOUNTER30          0xb1eU
#define CSR_MHPMCOUNTER31          0xb1fU
#define CSR_MUCOUNTEREN            0x320U
#define CSR_MSCOUNTEREN            0x321U
#define CSR_MHPMEVENT3             0x323U
#define CSR_MHPMEVENT4             0x324U
#define CSR_MHPMEVENT5             0x325U
#define CSR_MHPMEVENT6             0x326U
#define CSR_MHPMEVENT7             0x327U
#define CSR_MHPMEVENT8             0x328U
#define CSR_MHPMEVENT9             0x329U
#define CSR_MHPMEVENT10            0x32aU
#define CSR_MHPMEVENT11            0x32bU
#define CSR_MHPMEVENT12            0x32cU
#define CSR_MHPMEVENT13            0x32dU
#define CSR_MHPMEVENT14            0x32eU
#define CSR_MHPMEVENT15            0x32fU
#define CSR_MHPMEVENT16            0x330U
#define CSR_MHPMEVENT17            0x331U
#define CSR_MHPMEVENT18            0x332U
#define CSR_MHPMEVENT19            0x333U
#define CSR_MHPMEVENT20            0x334U
#define CSR_MHPMEVENT21            0x335U
#define CSR_MHPMEVENT22            0x336U
#define CSR_MHPMEVENT23            0x337U
#define CSR_MHPMEVENT24            0x338U
#define CSR_MHPMEVENT25            0x339U
#define CSR_MHPMEVENT26            0x33aU
#define CSR_MHPMEVENT27            0x33bU
#define CSR_MHPMEVENT28            0x33cU
#define CSR_MHPMEVENT29            0x33dU
#define CSR_MHPMEVENT30            0x33eU
#define CSR_MHPMEVENT31            0x33fU
#define CSR_MVENDORID              0xf11U
#define CSR_MARCHID                0xf12U
#define CSR_MIMPID                 0xf13U
#define CSR_MHARTID                0xf14U
#define CSR_CYCLEH                 0xc80U
#define CSR_TIMEH                  0xc81U
#define CSR_INSTRETH               0xc82U
#define CSR_HPMCOUNTER3H           0xc83U
#define CSR_HPMCOUNTER4H           0xc84U
#define CSR_HPMCOUNTER5H           0xc85U
#define CSR_HPMCOUNTER6H           0xc86U
#define CSR_HPMCOUNTER7H           0xc87U
#define CSR_HPMCOUNTER8H           0xc88U
#define CSR_HPMCOUNTER9H           0xc89U
#define CSR_HPMCOUNTER10H          0xc8aU
#define CSR_HPMCOUNTER11H          0xc8bU
#define CSR_HPMCOUNTER12H          0xc8cU
#define CSR_HPMCOUNTER13H          0xc8dU
#define CSR_HPMCOUNTER14H          0xc8eU
#define CSR_HPMCOUNTER15H          0xc8fU
#define CSR_HPMCOUNTER16H          0xc90U
#define CSR_HPMCOUNTER17H          0xc91U
#define CSR_HPMCOUNTER18H          0xc92U
#define CSR_HPMCOUNTER19H          0xc93U
#define CSR_HPMCOUNTER20H          0xc94U
#define CSR_HPMCOUNTER21H          0xc95U
#define CSR_HPMCOUNTER22H          0xc96U
#define CSR_HPMCOUNTER23H          0xc97U
#define CSR_HPMCOUNTER24H          0xc98U
#define CSR_HPMCOUNTER25H          0xc99U
#define CSR_HPMCOUNTER26H          0xc9aU
#define CSR_HPMCOUNTER27H          0xc9bU
#define CSR_HPMCOUNTER28H          0xc9cU
#define CSR_HPMCOUNTER29H          0xc9dU
#define CSR_HPMCOUNTER30H          0xc9eU
#define CSR_HPMCOUNTER31H          0xc9fU
#define CSR_MCYCLEH                0xb80U
#define CSR_MINSTRETH              0xb82U
#define CSR_MHPMCOUNTER3H          0xb83U
#define CSR_MHPMCOUNTER4H          0xb84U
#define CSR_MHPMCOUNTER5H          0xb85U
#define CSR_MHPMCOUNTER6H          0xb86U
#define CSR_MHPMCOUNTER7H          0xb87U
#define CSR_MHPMCOUNTER8H          0xb88U
#define CSR_MHPMCOUNTER9H          0xb89U
#define CSR_MHPMCOUNTER10H         0xb8aU
#define CSR_MHPMCOUNTER11H         0xb8bU
#define CSR_MHPMCOUNTER12H         0xb8cU
#define CSR_MHPMCOUNTER13H         0xb8dU
#define CSR_MHPMCOUNTER14H         0xb8eU
#define CSR_MHPMCOUNTER15H         0xb8fU
#define CSR_MHPMCOUNTER16H         0xb90U
#define CSR_MHPMCOUNTER17H         0xb91U
#define CSR_MHPMCOUNTER18H         0xb92U
#define CSR_MHPMCOUNTER19H         0xb93U
#define CSR_MHPMCOUNTER20H         0xb94U
#define CSR_MHPMCOUNTER21H         0xb95U
#define CSR_MHPMCOUNTER22H         0xb96U
#define CSR_MHPMCOUNTER23H         0xb97U
#define CSR_MHPMCOUNTER24H         0xb98U
#define CSR_MHPMCOUNTER25H         0xb99U
#define CSR_MHPMCOUNTER26H         0xb9aU
#define CSR_MHPMCOUNTER27H         0xb9bU
#define CSR_MHPMCOUNTER28H         0xb9cU
#define CSR_MHPMCOUNTER29H         0xb9dU
#define CSR_MHPMCOUNTER30H         0xb9eU
#define CSR_MHPMCOUNTER31H         0xb9fU
#define CAUSE_MISALIGNED_FETCH     0x0
#define CAUSE_FAULT_FETCH          0x1
#define CAUSE_ILLEGAL_INSTRUCTION  0x2
#define CAUSE_BREAKPOINT           0x3
#define CAUSE_MISALIGNED_LOAD      0x4
#define CAUSE_FAULT_LOAD           0x5
#define CAUSE_MISALIGNED_STORE     0x6
#define CAUSE_FAULT_STORE          0x7
#define CAUSE_USER_ECALL           0x8
#define CAUSE_SUPERVISOR_ECALL     0x9
#define CAUSE_HYPERVISOR_ECALL     0xa
#define CAUSE_MACHINE_ECALL        0xb
#endif
#if defined(DECLARE_INSN)
DECLARE_INSN(beq, MATCH_BEQ, MASK_BEQ)
DECLARE_INSN(bne, MATCH_BNE, MASK_BNE)
DECLARE_INSN(blt, MATCH_BLT, MASK_BLT)
DECLARE_INSN(bge, MATCH_BGE, MASK_BGE)
DECLARE_INSN(bltu, MATCH_BLTU, MASK_BLTU)
DECLARE_INSN(bgeu, MATCH_BGEU, MASK_BGEU)
DECLARE_INSN(jalr, MATCH_JALR, MASK_JALR)
DECLARE_INSN(jal, MATCH_JAL, MASK_JAL)
DECLARE_INSN(lui, MATCH_LUI, MASK_LUI)
DECLARE_INSN(auipc, MATCH_AUIPC, MASK_AUIPC)
DECLARE_INSN(addi, MATCH_ADDI, MASK_ADDI)
DECLARE_INSN(slli, MATCH_SLLI, MASK_SLLI)
DECLARE_INSN(slti, MATCH_SLTI, MASK_SLTI)
DECLARE_INSN(sltiu, MATCH_SLTIU, MASK_SLTIU)
DECLARE_INSN(xori, MATCH_XORI, MASK_XORI)
DECLARE_INSN(srli, MATCH_SRLI, MASK_SRLI)
DECLARE_INSN(srai, MATCH_SRAI, MASK_SRAI)
DECLARE_INSN(ori, MATCH_ORI, MASK_ORI)
DECLARE_INSN(andi, MATCH_ANDI, MASK_ANDI)
DECLARE_INSN(add, MATCH_ADD, MASK_ADD)
DECLARE_INSN(sub, MATCH_SUB, MASK_SUB)
DECLARE_INSN(sll, MATCH_SLL, MASK_SLL)
DECLARE_INSN(slt, MATCH_SLT, MASK_SLT)
DECLARE_INSN(sltu, MATCH_SLTU, MASK_SLTU)
DECLARE_INSN(xor, MATCH_XOR, MASK_XOR)
DECLARE_INSN(srl, MATCH_SRL, MASK_SRL)
DECLARE_INSN(sra, MATCH_SRA, MASK_SRA)
DECLARE_INSN(or, MATCH_OR, MASK_OR)
DECLARE_INSN(and, MATCH_AND, MASK_AND)
DECLARE_INSN(addiw, MATCH_ADDIW, MASK_ADDIW)
DECLARE_INSN(slliw, MATCH_SLLIW, MASK_SLLIW)
DECLARE_INSN(srliw, MATCH_SRLIW, MASK_SRLIW)
DECLARE_INSN(sraiw, MATCH_SRAIW, MASK_SRAIW)
DECLARE_INSN(addw, MATCH_ADDW, MASK_ADDW)
DECLARE_INSN(subw, MATCH_SUBW, MASK_SUBW)
DECLARE_INSN(sllw, MATCH_SLLW, MASK_SLLW)
DECLARE_INSN(srlw, MATCH_SRLW, MASK_SRLW)
DECLARE_INSN(sraw, MATCH_SRAW, MASK_SRAW)
DECLARE_INSN(lb, MATCH_LB, MASK_LB)
DECLARE_INSN(lh, MATCH_LH, MASK_LH)
DECLARE_INSN(lw, MATCH_LW, MASK_LW)
DECLARE_INSN(ld, MATCH_LD, MASK_LD)
DECLARE_INSN(lbu, MATCH_LBU, MASK_LBU)
DECLARE_INSN(lhu, MATCH_LHU, MASK_LHU)
DECLARE_INSN(lwu, MATCH_LWU, MASK_LWU)
DECLARE_INSN(sb, MATCH_SB, MASK_SB)
DECLARE_INSN(sh, MATCH_SH, MASK_SH)
DECLARE_INSN(sw, MATCH_SW, MASK_SW)
DECLARE_INSN(sd, MATCH_SD, MASK_SD)
DECLARE_INSN(fence, MATCH_FENCE, MASK_FENCE)
DECLARE_INSN(fence_i, MATCH_FENCE_I, MASK_FENCE_I)
DECLARE_INSN(mul, MATCH_MUL, MASK_MUL)
DECLARE_INSN(mulh, MATCH_MULH, MASK_MULH)
DECLARE_INSN(mulhsu, MATCH_MULHSU, MASK_MULHSU)
DECLARE_INSN(mulhu, MATCH_MULHU, MASK_MULHU)
DECLARE_INSN(div, MATCH_DIV, MASK_DIV)
DECLARE_INSN(divu, MATCH_DIVU, MASK_DIVU)
DECLARE_INSN(rem, MATCH_REM, MASK_REM)
DECLARE_INSN(remu, MATCH_REMU, MASK_REMU)
DECLARE_INSN(mulw, MATCH_MULW, MASK_MULW)
DECLARE_INSN(divw, MATCH_DIVW, MASK_DIVW)
DECLARE_INSN(divuw, MATCH_DIVUW, MASK_DIVUW)
DECLARE_INSN(remw, MATCH_REMW, MASK_REMW)
DECLARE_INSN(remuw, MATCH_REMUW, MASK_REMUW)
DECLARE_INSN(amoadd_w, MATCH_AMOADD_W, MASK_AMOADD_W)
DECLARE_INSN(amoxor_w, MATCH_AMOXOR_W, MASK_AMOXOR_W)
DECLARE_INSN(amoor_w, MATCH_AMOOR_W, MASK_AMOOR_W)
DECLARE_INSN(amoand_w, MATCH_AMOAND_W, MASK_AMOAND_W)
DECLARE_INSN(amomin_w, MATCH_AMOMIN_W, MASK_AMOMIN_W)
DECLARE_INSN(amomax_w, MATCH_AMOMAX_W, MASK_AMOMAX_W)
DECLARE_INSN(amominu_w, MATCH_AMOMINU_W, MASK_AMOMINU_W)
DECLARE_INSN(amomaxu_w, MATCH_AMOMAXU_W, MASK_AMOMAXU_W)
DECLARE_INSN(amoswap_w, MATCH_AMOSWAP_W, MASK_AMOSWAP_W)
DECLARE_INSN(lr_w, MATCH_LR_W, MASK_LR_W)
DECLARE_INSN(sc_w, MATCH_SC_W, MASK_SC_W)
DECLARE_INSN(amoadd_d, MATCH_AMOADD_D, MASK_AMOADD_D)
DECLARE_INSN(amoxor_d, MATCH_AMOXOR_D, MASK_AMOXOR_D)
DECLARE_INSN(amoor_d, MATCH_AMOOR_D, MASK_AMOOR_D)
DECLARE_INSN(amoand_d, MATCH_AMOAND_D, MASK_AMOAND_D)
DECLARE_INSN(amomin_d, MATCH_AMOMIN_D, MASK_AMOMIN_D)
DECLARE_INSN(amomax_d, MATCH_AMOMAX_D, MASK_AMOMAX_D)
DECLARE_INSN(amominu_d, MATCH_AMOMINU_D, MASK_AMOMINU_D)
DECLARE_INSN(amomaxu_d, MATCH_AMOMAXU_D, MASK_AMOMAXU_D)
DECLARE_INSN(amoswap_d, MATCH_AMOSWAP_D, MASK_AMOSWAP_D)
DECLARE_INSN(lr_d, MATCH_LR_D, MASK_LR_D)
DECLARE_INSN(sc_d, MATCH_SC_D, MASK_SC_D)
DECLARE_INSN(ecall, MATCH_ECALL, MASK_ECALL)
DECLARE_INSN(ebreak, MATCH_EBREAK, MASK_EBREAK)
DECLARE_INSN(uret, MATCH_URET, MASK_URET)
DECLARE_INSN(sret, MATCH_SRET, MASK_SRET)
DECLARE_INSN(hret, MATCH_HRET, MASK_HRET)
DECLARE_INSN(mret, MATCH_MRET, MASK_MRET)
DECLARE_INSN(dret, MATCH_DRET, MASK_DRET)
DECLARE_INSN(sfence_vm, MATCH_SFENCE_VM, MASK_SFENCE_VM)
DECLARE_INSN(wfi, MATCH_WFI, MASK_WFI)
DECLARE_INSN(csrrw, MATCH_CSRRW, MASK_CSRRW)
DECLARE_INSN(csrrs, MATCH_CSRRS, MASK_CSRRS)
DECLARE_INSN(csrrc, MATCH_CSRRC, MASK_CSRRC)
DECLARE_INSN(csrrwi, MATCH_CSRRWI, MASK_CSRRWI)
DECLARE_INSN(csrrsi, MATCH_CSRRSI, MASK_CSRRSI)
DECLARE_INSN(csrrci, MATCH_CSRRCI, MASK_CSRRCI)
DECLARE_INSN(fadd_s, MATCH_FADD_S, MASK_FADD_S)
DECLARE_INSN(fsub_s, MATCH_FSUB_S, MASK_FSUB_S)
DECLARE_INSN(fmul_s, MATCH_FMUL_S, MASK_FMUL_S)
DECLARE_INSN(fdiv_s, MATCH_FDIV_S, MASK_FDIV_S)
DECLARE_INSN(fsgnj_s, MATCH_FSGNJ_S, MASK_FSGNJ_S)
DECLARE_INSN(fsgnjn_s, MATCH_FSGNJN_S, MASK_FSGNJN_S)
DECLARE_INSN(fsgnjx_s, MATCH_FSGNJX_S, MASK_FSGNJX_S)
DECLARE_INSN(fmin_s, MATCH_FMIN_S, MASK_FMIN_S)
DECLARE_INSN(fmax_s, MATCH_FMAX_S, MASK_FMAX_S)
DECLARE_INSN(fsqrt_s, MATCH_FSQRT_S, MASK_FSQRT_S)
DECLARE_INSN(fadd_d, MATCH_FADD_D, MASK_FADD_D)
DECLARE_INSN(fsub_d, MATCH_FSUB_D, MASK_FSUB_D)
DECLARE_INSN(fmul_d, MATCH_FMUL_D, MASK_FMUL_D)
DECLARE_INSN(fdiv_d, MATCH_FDIV_D, MASK_FDIV_D)
DECLARE_INSN(fsgnj_d, MATCH_FSGNJ_D, MASK_FSGNJ_D)
DECLARE_INSN(fsgnjn_d, MATCH_FSGNJN_D, MASK_FSGNJN_D)
DECLARE_INSN(fsgnjx_d, MATCH_FSGNJX_D, MASK_FSGNJX_D)
DECLARE_INSN(fmin_d, MATCH_FMIN_D, MASK_FMIN_D)
DECLARE_INSN(fmax_d, MATCH_FMAX_D, MASK_FMAX_D)
DECLARE_INSN(fcvt_s_d, MATCH_FCVT_S_D, MASK_FCVT_S_D)
DECLARE_INSN(fcvt_d_s, MATCH_FCVT_D_S, MASK_FCVT_D_S)
DECLARE_INSN(fsqrt_d, MATCH_FSQRT_D, MASK_FSQRT_D)
DECLARE_INSN(fle_s, MATCH_FLE_S, MASK_FLE_S)
DECLARE_INSN(flt_s, MATCH_FLT_S, MASK_FLT_S)
DECLARE_INSN(feq_s, MATCH_FEQ_S, MASK_FEQ_S)
DECLARE_INSN(fle_d, MATCH_FLE_D, MASK_FLE_D)
DECLARE_INSN(flt_d, MATCH_FLT_D, MASK_FLT_D)
DECLARE_INSN(feq_d, MATCH_FEQ_D, MASK_FEQ_D)
DECLARE_INSN(fcvt_w_s, MATCH_FCVT_W_S, MASK_FCVT_W_S)
DECLARE_INSN(fcvt_wu_s, MATCH_FCVT_WU_S, MASK_FCVT_WU_S)
DECLARE_INSN(fcvt_l_s, MATCH_FCVT_L_S, MASK_FCVT_L_S)
DECLARE_INSN(fcvt_lu_s, MATCH_FCVT_LU_S, MASK_FCVT_LU_S)
DECLARE_INSN(fmv_x_s, MATCH_FMV_X_S, MASK_FMV_X_S)
DECLARE_INSN(fclass_s, MATCH_FCLASS_S, MASK_FCLASS_S)
DECLARE_INSN(fcvt_w_d, MATCH_FCVT_W_D, MASK_FCVT_W_D)
DECLARE_INSN(fcvt_wu_d, MATCH_FCVT_WU_D, MASK_FCVT_WU_D)
DECLARE_INSN(fcvt_l_d, MATCH_FCVT_L_D, MASK_FCVT_L_D)
DECLARE_INSN(fcvt_lu_d, MATCH_FCVT_LU_D, MASK_FCVT_LU_D)
DECLARE_INSN(fmv_x_d, MATCH_FMV_X_D, MASK_FMV_X_D)
DECLARE_INSN(fclass_d, MATCH_FCLASS_D, MASK_FCLASS_D)
DECLARE_INSN(fcvt_s_w, MATCH_FCVT_S_W, MASK_FCVT_S_W)
DECLARE_INSN(fcvt_s_wu, MATCH_FCVT_S_WU, MASK_FCVT_S_WU)
DECLARE_INSN(fcvt_s_l, MATCH_FCVT_S_L, MASK_FCVT_S_L)
DECLARE_INSN(fcvt_s_lu, MATCH_FCVT_S_LU, MASK_FCVT_S_LU)
DECLARE_INSN(fmv_s_x, MATCH_FMV_S_X, MASK_FMV_S_X)
DECLARE_INSN(fcvt_d_w, MATCH_FCVT_D_W, MASK_FCVT_D_W)
DECLARE_INSN(fcvt_d_wu, MATCH_FCVT_D_WU, MASK_FCVT_D_WU)
DECLARE_INSN(fcvt_d_l, MATCH_FCVT_D_L, MASK_FCVT_D_L)
DECLARE_INSN(fcvt_d_lu, MATCH_FCVT_D_LU, MASK_FCVT_D_LU)
DECLARE_INSN(fmv_d_x, MATCH_FMV_D_X, MASK_FMV_D_X)
DECLARE_INSN(flw, MATCH_FLW, MASK_FLW)
DECLARE_INSN(fld, MATCH_FLD, MASK_FLD)
DECLARE_INSN(fsw, MATCH_FSW, MASK_FSW)
DECLARE_INSN(fsd, MATCH_FSD, MASK_FSD)
DECLARE_INSN(fmadd_s, MATCH_FMADD_S, MASK_FMADD_S)
DECLARE_INSN(fmsub_s, MATCH_FMSUB_S, MASK_FMSUB_S)
DECLARE_INSN(fnmsub_s, MATCH_FNMSUB_S, MASK_FNMSUB_S)
DECLARE_INSN(fnmadd_s, MATCH_FNMADD_S, MASK_FNMADD_S)
DECLARE_INSN(fmadd_d, MATCH_FMADD_D, MASK_FMADD_D)
DECLARE_INSN(fmsub_d, MATCH_FMSUB_D, MASK_FMSUB_D)
DECLARE_INSN(fnmsub_d, MATCH_FNMSUB_D, MASK_FNMSUB_D)
DECLARE_INSN(fnmadd_d, MATCH_FNMADD_D, MASK_FNMADD_D)
DECLARE_INSN(c_nop, MATCH_C_NOP, MASK_C_NOP)
DECLARE_INSN(c_addi16sp, MATCH_C_ADDI16SP, MASK_C_ADDI16SP)
DECLARE_INSN(c_jr, MATCH_C_JR, MASK_C_JR)
DECLARE_INSN(c_jalr, MATCH_C_JALR, MASK_C_JALR)
DECLARE_INSN(c_ebreak, MATCH_C_EBREAK, MASK_C_EBREAK)
DECLARE_INSN(c_ld, MATCH_C_LD, MASK_C_LD)
DECLARE_INSN(c_sd, MATCH_C_SD, MASK_C_SD)
DECLARE_INSN(c_addiw, MATCH_C_ADDIW, MASK_C_ADDIW)
DECLARE_INSN(c_ldsp, MATCH_C_LDSP, MASK_C_LDSP)
DECLARE_INSN(c_sdsp, MATCH_C_SDSP, MASK_C_SDSP)
DECLARE_INSN(c_addi4spn, MATCH_C_ADDI4SPN, MASK_C_ADDI4SPN)
DECLARE_INSN(c_fld, MATCH_C_FLD, MASK_C_FLD)
DECLARE_INSN(c_lw, MATCH_C_LW, MASK_C_LW)
DECLARE_INSN(c_flw, MATCH_C_FLW, MASK_C_FLW)
DECLARE_INSN(c_fsd, MATCH_C_FSD, MASK_C_FSD)
DECLARE_INSN(c_sw, MATCH_C_SW, MASK_C_SW)
DECLARE_INSN(c_fsw, MATCH_C_FSW, MASK_C_FSW)
DECLARE_INSN(c_addi, MATCH_C_ADDI, MASK_C_ADDI)
DECLARE_INSN(c_jal, MATCH_C_JAL, MASK_C_JAL)
DECLARE_INSN(c_li, MATCH_C_LI, MASK_C_LI)
DECLARE_INSN(c_lui, MATCH_C_LUI, MASK_C_LUI)
DECLARE_INSN(c_srli, MATCH_C_SRLI, MASK_C_SRLI)
DECLARE_INSN(c_srai, MATCH_C_SRAI, MASK_C_SRAI)
DECLARE_INSN(c_andi, MATCH_C_ANDI, MASK_C_ANDI)
DECLARE_INSN(c_sub, MATCH_C_SUB, MASK_C_SUB)
DECLARE_INSN(c_xor, MATCH_C_XOR, MASK_C_XOR)
DECLARE_INSN(c_or, MATCH_C_OR, MASK_C_OR)
DECLARE_INSN(c_and, MATCH_C_AND, MASK_C_AND)
DECLARE_INSN(c_subw, MATCH_C_SUBW, MASK_C_SUBW)
DECLARE_INSN(c_addw, MATCH_C_ADDW, MASK_C_ADDW)
DECLARE_INSN(c_j, MATCH_C_J, MASK_C_J)
DECLARE_INSN(c_beqz, MATCH_C_BEQZ, MASK_C_BEQZ)
DECLARE_INSN(c_bnez, MATCH_C_BNEZ, MASK_C_BNEZ)
DECLARE_INSN(c_slli, MATCH_C_SLLI, MASK_C_SLLI)
DECLARE_INSN(c_fldsp, MATCH_C_FLDSP, MASK_C_FLDSP)
DECLARE_INSN(c_lwsp, MATCH_C_LWSP, MASK_C_LWSP)
DECLARE_INSN(c_flwsp, MATCH_C_FLWSP, MASK_C_FLWSP)
DECLARE_INSN(c_mv, MATCH_C_MV, MASK_C_MV)
DECLARE_INSN(c_add, MATCH_C_ADD, MASK_C_ADD)
DECLARE_INSN(c_fsdsp, MATCH_C_FSDSP, MASK_C_FSDSP)
DECLARE_INSN(c_swsp, MATCH_C_SWSP, MASK_C_SWSP)
DECLARE_INSN(c_fswsp, MATCH_C_FSWSP, MASK_C_FSWSP)
DECLARE_INSN(custom0, MATCH_CUSTOM0, MASK_CUSTOM0)
DECLARE_INSN(custom0_rs1, MATCH_CUSTOM0_RS1, MASK_CUSTOM0_RS1)
DECLARE_INSN(custom0_rs1_rs2, MATCH_CUSTOM0_RS1_RS2, MASK_CUSTOM0_RS1_RS2)
DECLARE_INSN(custom0_rd, MATCH_CUSTOM0_RD, MASK_CUSTOM0_RD)
DECLARE_INSN(custom0_rd_rs1, MATCH_CUSTOM0_RD_RS1, MASK_CUSTOM0_RD_RS1)
DECLARE_INSN(custom0_rd_rs1_rs2, MATCH_CUSTOM0_RD_RS1_RS2, MASK_CUSTOM0_RD_RS1_RS2)
DECLARE_INSN(custom1, MATCH_CUSTOM1, MASK_CUSTOM1)
DECLARE_INSN(custom1_rs1, MATCH_CUSTOM1_RS1, MASK_CUSTOM1_RS1)
DECLARE_INSN(custom1_rs1_rs2, MATCH_CUSTOM1_RS1_RS2, MASK_CUSTOM1_RS1_RS2)
DECLARE_INSN(custom1_rd, MATCH_CUSTOM1_RD, MASK_CUSTOM1_RD)
DECLARE_INSN(custom1_rd_rs1, MATCH_CUSTOM1_RD_RS1, MASK_CUSTOM1_RD_RS1)
DECLARE_INSN(custom1_rd_rs1_rs2, MATCH_CUSTOM1_RD_RS1_RS2, MASK_CUSTOM1_RD_RS1_RS2)
DECLARE_INSN(custom2, MATCH_CUSTOM2, MASK_CUSTOM2)
DECLARE_INSN(custom2_rs1, MATCH_CUSTOM2_RS1, MASK_CUSTOM2_RS1)
DECLARE_INSN(custom2_rs1_rs2, MATCH_CUSTOM2_RS1_RS2, MASK_CUSTOM2_RS1_RS2)
DECLARE_INSN(custom2_rd, MATCH_CUSTOM2_RD, MASK_CUSTOM2_RD)
DECLARE_INSN(custom2_rd_rs1, MATCH_CUSTOM2_RD_RS1, MASK_CUSTOM2_RD_RS1)
DECLARE_INSN(custom2_rd_rs1_rs2, MATCH_CUSTOM2_RD_RS1_RS2, MASK_CUSTOM2_RD_RS1_RS2)
DECLARE_INSN(custom3, MATCH_CUSTOM3, MASK_CUSTOM3)
DECLARE_INSN(custom3_rs1, MATCH_CUSTOM3_RS1, MASK_CUSTOM3_RS1)
DECLARE_INSN(custom3_rs1_rs2, MATCH_CUSTOM3_RS1_RS2, MASK_CUSTOM3_RS1_RS2)
DECLARE_INSN(custom3_rd, MATCH_CUSTOM3_RD, MASK_CUSTOM3_RD)
DECLARE_INSN(custom3_rd_rs1, MATCH_CUSTOM3_RD_RS1, MASK_CUSTOM3_RD_RS1)
DECLARE_INSN(custom3_rd_rs1_rs2, MATCH_CUSTOM3_RD_RS1_RS2, MASK_CUSTOM3_RD_RS1_RS2)
#endif
#if defined(DECLARE_CSR)
DECLARE_CSR(fflags, CSR_FFLAGS)
DECLARE_CSR(frm, CSR_FRM)
DECLARE_CSR(fcsr, CSR_FCSR)
DECLARE_CSR(cycle, CSR_CYCLE)
DECLARE_CSR(time, CSR_TIME)
DECLARE_CSR(instret, CSR_INSTRET)
DECLARE_CSR(hpmcounter3, CSR_HPMCOUNTER3)
DECLARE_CSR(hpmcounter4, CSR_HPMCOUNTER4)
DECLARE_CSR(hpmcounter5, CSR_HPMCOUNTER5)
DECLARE_CSR(hpmcounter6, CSR_HPMCOUNTER6)
DECLARE_CSR(hpmcounter7, CSR_HPMCOUNTER7)
DECLARE_CSR(hpmcounter8, CSR_HPMCOUNTER8)
DECLARE_CSR(hpmcounter9, CSR_HPMCOUNTER9)
DECLARE_CSR(hpmcounter10, CSR_HPMCOUNTER10)
DECLARE_CSR(hpmcounter11, CSR_HPMCOUNTER11)
DECLARE_CSR(hpmcounter12, CSR_HPMCOUNTER12)
DECLARE_CSR(hpmcounter13, CSR_HPMCOUNTER13)
DECLARE_CSR(hpmcounter14, CSR_HPMCOUNTER14)
DECLARE_CSR(hpmcounter15, CSR_HPMCOUNTER15)
DECLARE_CSR(hpmcounter16, CSR_HPMCOUNTER16)
DECLARE_CSR(hpmcounter17, CSR_HPMCOUNTER17)
DECLARE_CSR(hpmcounter18, CSR_HPMCOUNTER18)
DECLARE_CSR(hpmcounter19, CSR_HPMCOUNTER19)
DECLARE_CSR(hpmcounter20, CSR_HPMCOUNTER20)
DECLARE_CSR(hpmcounter21, CSR_HPMCOUNTER21)
DECLARE_CSR(hpmcounter22, CSR_HPMCOUNTER22)
DECLARE_CSR(hpmcounter23, CSR_HPMCOUNTER23)
DECLARE_CSR(hpmcounter24, CSR_HPMCOUNTER24)
DECLARE_CSR(hpmcounter25, CSR_HPMCOUNTER25)
DECLARE_CSR(hpmcounter26, CSR_HPMCOUNTER26)
DECLARE_CSR(hpmcounter27, CSR_HPMCOUNTER27)
DECLARE_CSR(hpmcounter28, CSR_HPMCOUNTER28)
DECLARE_CSR(hpmcounter29, CSR_HPMCOUNTER29)
DECLARE_CSR(hpmcounter30, CSR_HPMCOUNTER30)
DECLARE_CSR(hpmcounter31, CSR_HPMCOUNTER31)
DECLARE_CSR(sstatus, CSR_SSTATUS)
DECLARE_CSR(sie, CSR_SIE)
DECLARE_CSR(stvec, CSR_STVEC)
DECLARE_CSR(sscratch, CSR_SSCRATCH)
DECLARE_CSR(sepc, CSR_SEPC)
DECLARE_CSR(scause, CSR_SCAUSE)
DECLARE_CSR(sbadaddr, CSR_SBADADDR)
DECLARE_CSR(sip, CSR_SIP)
DECLARE_CSR(sptbr, CSR_SPTBR)
DECLARE_CSR(mstatus, CSR_MSTATUS)
DECLARE_CSR(misa, CSR_MISA)
DECLARE_CSR(medeleg, CSR_MEDELEG)
DECLARE_CSR(mideleg, CSR_MIDELEG)
DECLARE_CSR(mie, CSR_MIE)
DECLARE_CSR(mtvec, CSR_MTVEC)
DECLARE_CSR(mscratch, CSR_MSCRATCH)
DECLARE_CSR(mepc, CSR_MEPC)
DECLARE_CSR(mcause, CSR_MCAUSE)
DECLARE_CSR(mbadaddr, CSR_MBADADDR)
DECLARE_CSR(mip, CSR_MIP)
DECLARE_CSR(tselect, CSR_TSELECT)
DECLARE_CSR(tdata1, CSR_TDATA1)
DECLARE_CSR(tdata2, CSR_TDATA2)
DECLARE_CSR(tdata3, CSR_TDATA3)
DECLARE_CSR(dcsr, CSR_DCSR)
DECLARE_CSR(dpc, CSR_DPC)
DECLARE_CSR(dscratch, CSR_DSCRATCH)
DECLARE_CSR(mcycle, CSR_MCYCLE)
DECLARE_CSR(minstret, CSR_MINSTRET)
DECLARE_CSR(mhpmcounter3, CSR_MHPMCOUNTER3)
DECLARE_CSR(mhpmcounter4, CSR_MHPMCOUNTER4)
DECLARE_CSR(mhpmcounter5, CSR_MHPMCOUNTER5)
DECLARE_CSR(mhpmcounter6, CSR_MHPMCOUNTER6)
DECLARE_CSR(mhpmcounter7, CSR_MHPMCOUNTER7)
DECLARE_CSR(mhpmcounter8, CSR_MHPMCOUNTER8)
DECLARE_CSR(mhpmcounter9, CSR_MHPMCOUNTER9)
DECLARE_CSR(mhpmcounter10, CSR_MHPMCOUNTER10)
DECLARE_CSR(mhpmcounter11, CSR_MHPMCOUNTER11)
DECLARE_CSR(mhpmcounter12, CSR_MHPMCOUNTER12)
DECLARE_CSR(mhpmcounter13, CSR_MHPMCOUNTER13)
DECLARE_CSR(mhpmcounter14, CSR_MHPMCOUNTER14)
DECLARE_CSR(mhpmcounter15, CSR_MHPMCOUNTER15)
DECLARE_CSR(mhpmcounter16, CSR_MHPMCOUNTER16)
DECLARE_CSR(mhpmcounter17, CSR_MHPMCOUNTER17)
DECLARE_CSR(mhpmcounter18, CSR_MHPMCOUNTER18)
DECLARE_CSR(mhpmcounter19, CSR_MHPMCOUNTER19)
DECLARE_CSR(mhpmcounter20, CSR_MHPMCOUNTER20)
DECLARE_CSR(mhpmcounter21, CSR_MHPMCOUNTER21)
DECLARE_CSR(mhpmcounter22, CSR_MHPMCOUNTER22)
DECLARE_CSR(mhpmcounter23, CSR_MHPMCOUNTER23)
DECLARE_CSR(mhpmcounter24, CSR_MHPMCOUNTER24)
DECLARE_CSR(mhpmcounter25, CSR_MHPMCOUNTER25)
DECLARE_CSR(mhpmcounter26, CSR_MHPMCOUNTER26)
DECLARE_CSR(mhpmcounter27, CSR_MHPMCOUNTER27)
DECLARE_CSR(mhpmcounter28, CSR_MHPMCOUNTER28)
DECLARE_CSR(mhpmcounter29, CSR_MHPMCOUNTER29)
DECLARE_CSR(mhpmcounter30, CSR_MHPMCOUNTER30)
DECLARE_CSR(mhpmcounter31, CSR_MHPMCOUNTER31)
DECLARE_CSR(mucounteren, CSR_MUCOUNTEREN)
DECLARE_CSR(mscounteren, CSR_MSCOUNTEREN)
DECLARE_CSR(mhpmevent3, CSR_MHPMEVENT3)
DECLARE_CSR(mhpmevent4, CSR_MHPMEVENT4)
DECLARE_CSR(mhpmevent5, CSR_MHPMEVENT5)
DECLARE_CSR(mhpmevent6, CSR_MHPMEVENT6)
DECLARE_CSR(mhpmevent7, CSR_MHPMEVENT7)
DECLARE_CSR(mhpmevent8, CSR_MHPMEVENT8)
DECLARE_CSR(mhpmevent9, CSR_MHPMEVENT9)
DECLARE_CSR(mhpmevent10, CSR_MHPMEVENT10)
DECLARE_CSR(mhpmevent11, CSR_MHPMEVENT11)
DECLARE_CSR(mhpmevent12, CSR_MHPMEVENT12)
DECLARE_CSR(mhpmevent13, CSR_MHPMEVENT13)
DECLARE_CSR(mhpmevent14, CSR_MHPMEVENT14)
DECLARE_CSR(mhpmevent15, CSR_MHPMEVENT15)
DECLARE_CSR(mhpmevent16, CSR_MHPMEVENT16)
DECLARE_CSR(mhpmevent17, CSR_MHPMEVENT17)
DECLARE_CSR(mhpmevent18, CSR_MHPMEVENT18)
DECLARE_CSR(mhpmevent19, CSR_MHPMEVENT19)
DECLARE_CSR(mhpmevent20, CSR_MHPMEVENT20)
DECLARE_CSR(mhpmevent21, CSR_MHPMEVENT21)
DECLARE_CSR(mhpmevent22, CSR_MHPMEVENT22)
DECLARE_CSR(mhpmevent23, CSR_MHPMEVENT23)
DECLARE_CSR(mhpmevent24, CSR_MHPMEVENT24)
DECLARE_CSR(mhpmevent25, CSR_MHPMEVENT25)
DECLARE_CSR(mhpmevent26, CSR_MHPMEVENT26)
DECLARE_CSR(mhpmevent27, CSR_MHPMEVENT27)
DECLARE_CSR(mhpmevent28, CSR_MHPMEVENT28)
DECLARE_CSR(mhpmevent29, CSR_MHPMEVENT29)
DECLARE_CSR(mhpmevent30, CSR_MHPMEVENT30)
DECLARE_CSR(mhpmevent31, CSR_MHPMEVENT31)
DECLARE_CSR(mvendorid, CSR_MVENDORID)
DECLARE_CSR(marchid, CSR_MARCHID)
DECLARE_CSR(mimpid, CSR_MIMPID)
DECLARE_CSR(mhartid, CSR_MHARTID)
DECLARE_CSR(cycleh, CSR_CYCLEH)
DECLARE_CSR(timeh, CSR_TIMEH)
DECLARE_CSR(instreth, CSR_INSTRETH)
DECLARE_CSR(hpmcounter3h, CSR_HPMCOUNTER3H)
DECLARE_CSR(hpmcounter4h, CSR_HPMCOUNTER4H)
DECLARE_CSR(hpmcounter5h, CSR_HPMCOUNTER5H)
DECLARE_CSR(hpmcounter6h, CSR_HPMCOUNTER6H)
DECLARE_CSR(hpmcounter7h, CSR_HPMCOUNTER7H)
DECLARE_CSR(hpmcounter8h, CSR_HPMCOUNTER8H)
DECLARE_CSR(hpmcounter9h, CSR_HPMCOUNTER9H)
DECLARE_CSR(hpmcounter10h, CSR_HPMCOUNTER10H)
DECLARE_CSR(hpmcounter11h, CSR_HPMCOUNTER11H)
DECLARE_CSR(hpmcounter12h, CSR_HPMCOUNTER12H)
DECLARE_CSR(hpmcounter13h, CSR_HPMCOUNTER13H)
DECLARE_CSR(hpmcounter14h, CSR_HPMCOUNTER14H)
DECLARE_CSR(hpmcounter15h, CSR_HPMCOUNTER15H)
DECLARE_CSR(hpmcounter16h, CSR_HPMCOUNTER16H)
DECLARE_CSR(hpmcounter17h, CSR_HPMCOUNTER17H)
DECLARE_CSR(hpmcounter18h, CSR_HPMCOUNTER18H)
DECLARE_CSR(hpmcounter19h, CSR_HPMCOUNTER19H)
DECLARE_CSR(hpmcounter20h, CSR_HPMCOUNTER20H)
DECLARE_CSR(hpmcounter21h, CSR_HPMCOUNTER21H)
DECLARE_CSR(hpmcounter22h, CSR_HPMCOUNTER22H)
DECLARE_CSR(hpmcounter23h, CSR_HPMCOUNTER23H)
DECLARE_CSR(hpmcounter24h, CSR_HPMCOUNTER24H)
DECLARE_CSR(hpmcounter25h, CSR_HPMCOUNTER25H)
DECLARE_CSR(hpmcounter26h, CSR_HPMCOUNTER26H)
DECLARE_CSR(hpmcounter27h, CSR_HPMCOUNTER27H)
DECLARE_CSR(hpmcounter28h, CSR_HPMCOUNTER28H)
DECLARE_CSR(hpmcounter29h, CSR_HPMCOUNTER29H)
DECLARE_CSR(hpmcounter30h, CSR_HPMCOUNTER30H)
DECLARE_CSR(hpmcounter31h, CSR_HPMCOUNTER31H)
DECLARE_CSR(mcycleh, CSR_MCYCLEH)
DECLARE_CSR(minstreth, CSR_MINSTRETH)
DECLARE_CSR(mhpmcounter3h, CSR_MHPMCOUNTER3H)
DECLARE_CSR(mhpmcounter4h, CSR_MHPMCOUNTER4H)
DECLARE_CSR(mhpmcounter5h, CSR_MHPMCOUNTER5H)
DECLARE_CSR(mhpmcounter6h, CSR_MHPMCOUNTER6H)
DECLARE_CSR(mhpmcounter7h, CSR_MHPMCOUNTER7H)
DECLARE_CSR(mhpmcounter8h, CSR_MHPMCOUNTER8H)
DECLARE_CSR(mhpmcounter9h, CSR_MHPMCOUNTER9H)
DECLARE_CSR(mhpmcounter10h, CSR_MHPMCOUNTER10H)
DECLARE_CSR(mhpmcounter11h, CSR_MHPMCOUNTER11H)
DECLARE_CSR(mhpmcounter12h, CSR_MHPMCOUNTER12H)
DECLARE_CSR(mhpmcounter13h, CSR_MHPMCOUNTER13H)
DECLARE_CSR(mhpmcounter14h, CSR_MHPMCOUNTER14H)
DECLARE_CSR(mhpmcounter15h, CSR_MHPMCOUNTER15H)
DECLARE_CSR(mhpmcounter16h, CSR_MHPMCOUNTER16H)
DECLARE_CSR(mhpmcounter17h, CSR_MHPMCOUNTER17H)
DECLARE_CSR(mhpmcounter18h, CSR_MHPMCOUNTER18H)
DECLARE_CSR(mhpmcounter19h, CSR_MHPMCOUNTER19H)
DECLARE_CSR(mhpmcounter20h, CSR_MHPMCOUNTER20H)
DECLARE_CSR(mhpmcounter21h, CSR_MHPMCOUNTER21H)
DECLARE_CSR(mhpmcounter22h, CSR_MHPMCOUNTER22H)
DECLARE_CSR(mhpmcounter23h, CSR_MHPMCOUNTER23H)
DECLARE_CSR(mhpmcounter24h, CSR_MHPMCOUNTER24H)
DECLARE_CSR(mhpmcounter25h, CSR_MHPMCOUNTER25H)
DECLARE_CSR(mhpmcounter26h, CSR_MHPMCOUNTER26H)
DECLARE_CSR(mhpmcounter27h, CSR_MHPMCOUNTER27H)
DECLARE_CSR(mhpmcounter28h, CSR_MHPMCOUNTER28H)
DECLARE_CSR(mhpmcounter29h, CSR_MHPMCOUNTER29H)
DECLARE_CSR(mhpmcounter30h, CSR_MHPMCOUNTER30H)
DECLARE_CSR(mhpmcounter31h, CSR_MHPMCOUNTER31H)
#endif
#if defined(DECLARE_CAUSE)
DECLARE_CAUSE("misaligned fetch", CAUSE_MISALIGNED_FETCH)
DECLARE_CAUSE("fault fetch", CAUSE_FAULT_FETCH)
DECLARE_CAUSE("illegal instruction", CAUSE_ILLEGAL_INSTRUCTION)
DECLARE_CAUSE("breakpoint", CAUSE_BREAKPOINT)
DECLARE_CAUSE("misaligned load", CAUSE_MISALIGNED_LOAD)
DECLARE_CAUSE("fault load", CAUSE_FAULT_LOAD)
DECLARE_CAUSE("misaligned store", CAUSE_MISALIGNED_STORE)
DECLARE_CAUSE("fault store", CAUSE_FAULT_STORE)
DECLARE_CAUSE("user_ecall", CAUSE_USER_ECALL)
DECLARE_CAUSE("supervisor_ecall", CAUSE_SUPERVISOR_ECALL)
DECLARE_CAUSE("hypervisor_ecall", CAUSE_HYPERVISOR_ECALL)
DECLARE_CAUSE("machine_ecall", CAUSE_MACHINE_ECALL)
#endif

