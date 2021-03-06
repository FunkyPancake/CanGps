/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Peripherals v9.0
processor: MKE16F256xxx16
package_id: MKE16F256VLH16
mcu_data: ksdk2_0
processor_version: 9.0.0
functionalGroups:
- name: BOARD_InitPeripherals
  UUID: 7bcc8dca-5c6b-49d0-b183-edd7f32a26ff
  called_from_default_init: true
  selectedCore: core0
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/

/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
component:
- type: 'system'
- type_id: 'system_54b53072540eeeb8f8e9343e71f28176'
- global_system_definitions:
  - user_definitions: ''
  - user_includes: ''
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */

/***********************************************************************************************************************
 * Included files
 **********************************************************************************************************************/
#include "peripherals.h"

/***********************************************************************************************************************
 * BOARD_InitPeripherals functional group
 **********************************************************************************************************************/
/***********************************************************************************************************************
 * DMA initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'DMA'
- type: 'edma'
- mode: 'basic'
- custom_name_enabled: 'false'
- type_id: 'edma_6d0dd4e17e2f179c7d42d98767129ede'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'DMA'
- config_sets:
  - fsl_edma:
    - common_settings:
      - enableContinuousLinkMode: 'false'
      - enableHaltOnError: 'true'
      - enableRoundRobinArbitration: 'false'
      - enableDebugMode: 'false'
    - dma_table: []
    - edma_channels: []
    - errInterruptConfig:
      - enableErrInterrupt: 'false'
      - errorInterrupt:
        - IRQn: 'DMA_Error_IRQn'
        - enable_interrrupt: 'enabled'
        - enable_priority: 'false'
        - priority: '0'
        - enable_custom_name: 'false'
    - quick_selection: 'default'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */
const edma_config_t DMA_config = {
  .enableContinuousLinkMode = false,
  .enableHaltOnError = true,
  .enableRoundRobinArbitration = false,
  .enableDebugMode = false
};

/* Empty initialization function (commented out)
static void DMA_init(void) {
} */

/***********************************************************************************************************************
 * CAN0 initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'CAN0'
- type: 'flexcan'
- mode: 'interrupts'
- custom_name_enabled: 'false'
- type_id: 'flexcan_477f6be3462ee2961b67c0825ef495e2'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'CAN0'
- config_sets:
  - interruptsCfg:
    - messageBufferIrqs: '0'
    - interruptsEnable: ''
    - enable_ored_mb_irq: 'false'
    - interrupt_ored_mb:
      - IRQn: 'CAN0_ORed_Message_buffer_IRQn'
      - enable_interrrupt: 'enabled'
      - enable_priority: 'false'
      - priority: '0'
      - enable_custom_name: 'false'
    - enable_busoff_irq: 'false'
    - interrupt_busoff:
      - IRQn: 'CAN0_ORed_IRQn'
      - enable_interrrupt: 'enabled'
      - enable_priority: 'false'
      - priority: '0'
      - enable_custom_name: 'false'
    - enable_error_irq: 'false'
    - interrupt_error:
      - IRQn: 'CAN0_Error_IRQn'
      - enable_interrrupt: 'enabled'
      - enable_priority: 'false'
      - priority: '0'
      - enable_custom_name: 'false'
    - enable_tx_irq: 'false'
    - interrupt_tx:
      - IRQn: 'CAN0_ORed_IRQn'
      - enable_interrrupt: 'enabled'
      - enable_priority: 'false'
      - priority: '0'
      - enable_custom_name: 'false'
    - enable_rx_irq: 'false'
    - interrupt_rx:
      - IRQn: 'CAN0_ORed_IRQn'
      - enable_interrrupt: 'enabled'
      - enable_priority: 'false'
      - priority: '0'
      - enable_custom_name: 'false'
    - enable_wakeup_irq: 'false'
    - interrupt_wakeup:
      - IRQn: 'CAN0_Wake_Up_IRQn'
      - enable_interrrupt: 'enabled'
      - enable_priority: 'false'
      - priority: '0'
      - enable_custom_name: 'false'
  - fsl_flexcan:
    - can_config:
      - clockSource: 'kFLEXCAN_ClkSrcPeri'
      - clockSourceFreq: 'BOARD_BootClockRUN'
      - wakeupSrc: 'kFLEXCAN_WakeupSrcUnfiltered'
      - baudRate: '1000000'
      - maxMbNum: '16'
      - enableLoopBack: 'false'
      - enableTimerSync: 'true'
      - enableSelfWakeup: 'false'
      - enableIndividMask: 'false'
      - disableSelfReception: 'false'
      - enableListenOnlyMode: 'false'
      - timingConfig:
        - propSeg: '7'
        - phaseSeg1: '4'
        - phaseSeg2: '2'
        - rJumpwidth: '2'
        - bitTime: []
    - enableRxFIFO: 'false'
    - rxFIFO:
      - idFilterTable: ''
      - idFilterNum: 'num0'
      - idFilterType: 'kFLEXCAN_RxFifoFilterTypeA'
      - priority: 'kFLEXCAN_RxFifoPrioLow'
    - channels:
      - 0:
        - mbID: '0'
        - mbType: 'mbRx'
        - rxMb:
          - id: '0'
          - format: 'kFLEXCAN_FrameFormatStandard'
          - type: 'kFLEXCAN_FrameTypeData'
      - 1:
        - mbID: '1'
        - mbType: 'mbTx'
        - rxMb:
          - id: '0'
          - format: 'kFLEXCAN_FrameFormatStandard'
          - type: 'kFLEXCAN_FrameTypeData'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */
const flexcan_config_t CAN0_config = {
  .clkSrc = kFLEXCAN_ClkSrc1,
  .wakeupSrc = kFLEXCAN_WakeupSrcUnfiltered,
  .baudRate = 1000000UL,
  .maxMbNum = 16U,
  .enableLoopBack = false,
  .enableTimerSync = true,
  .enableSelfWakeup = false,
  .enableIndividMask = false,
  .disableSelfReception = false,
  .enableListenOnlyMode = false,
  .timingConfig = {
    .preDivider = 5,
    .propSeg = 6,
    .phaseSeg1 = 3,
    .phaseSeg2 = 1,
    .rJumpwidth = 1
  }
};
/* Message buffer 0 configuration structure */
const flexcan_rx_mb_config_t CAN0_rx_mb_config_0 = {
  .id = 0UL,
  .format = kFLEXCAN_FrameFormatStandard,
  .type = kFLEXCAN_FrameTypeData
};

static void CAN0_init(void) {
  FLEXCAN_Init(CAN0_PERIPHERAL, &CAN0_config, CAN0_CLOCK_SOURCE);

  /* Message buffer 0 initialization */
  FLEXCAN_SetRxMbConfig(CAN0_PERIPHERAL, 0, &CAN0_rx_mb_config_0, true);
  /* Message buffer 1 initialization */
  FLEXCAN_SetTxMbConfig(CAN0_PERIPHERAL, 1, true);
}

/***********************************************************************************************************************
 * LPSPI0 initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'LPSPI0'
- type: 'lpspi'
- mode: 'freertos'
- custom_name_enabled: 'false'
- type_id: 'lpspi_6e21a1e0a09f0a012d683c4f91752db8'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'LPSPI0'
- config_sets:
  - transfer:
    - config:
      - transmitBuffer:
        - init: 'false'
      - receiveBuffer:
        - init: 'false'
      - dataSize: '10'
      - enableTransferStruct: 'defined'
      - flags: ''
  - main:
    - mode: 'kLPSPI_Master'
    - clockSource: 'LpspiClock'
    - clockSourceFreq: 'BOARD_BootClockRUN'
    - master:
      - baudRate: '2000000'
      - bitsPerFrame: '16'
      - cpol: 'kLPSPI_ClockPolarityActiveHigh'
      - cpha: 'kLPSPI_ClockPhaseFirstEdge'
      - direction: 'kLPSPI_MsbFirst'
      - pcsToSckDelayInNanoSec: '1000'
      - lastSckToPcsDelayInNanoSec: '1000'
      - betweenTransferDelayInNanoSec: '1000'
      - whichPcs: 'kLPSPI_Pcs0'
      - pcsActiveHighOrLow: 'kLPSPI_PcsActiveLow'
      - pinCfg: 'kLPSPI_SdiInSdoOut'
      - dataOutConfig: 'kLpspiDataOutRetained'
    - interrupt_priority:
      - IRQn: 'LPSPI0_IRQn'
      - enable_priority: 'true'
      - priority: '5'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */
const lpspi_master_config_t LPSPI0_config = {
  .baudRate = 2000000UL,
  .bitsPerFrame = 16UL,
  .cpol = kLPSPI_ClockPolarityActiveHigh,
  .cpha = kLPSPI_ClockPhaseSecondEdge,
  .direction = kLPSPI_LsbFirst,
  .pcsToSckDelayInNanoSec = 1000UL,
  .lastSckToPcsDelayInNanoSec = 1000UL,
  .betweenTransferDelayInNanoSec = 1000UL,
  .whichPcs = kLPSPI_Pcs0,
  .pcsActiveHighOrLow = kLPSPI_PcsActiveLow,
  .pinCfg = kLPSPI_SdiInSdoOut,
  .dataOutConfig = kLpspiDataOutRetained
};
lpspi_transfer_t LPSPI0_transfer = {
  .txData = NULL,
  .rxData = NULL,
  .dataSize = 10,
  .configFlags = 0
};
lpspi_rtos_handle_t LPSPI0_handle;

static void LPSPI0_init(void) {
  /* Interrupt vector LPSPI0_IRQn priority settings in the NVIC. */
  NVIC_SetPriority(LPSPI0_IRQN, LPSPI0_IRQ_PRIORITY);
  LPSPI_RTOS_Init(&LPSPI0_handle, LPSPI0_PERIPHERAL, &LPSPI0_config, LPSPI0_CLOCK_FREQ);
}

/***********************************************************************************************************************
 * NVIC initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'NVIC'
- type: 'nvic'
- mode: 'general'
- custom_name_enabled: 'false'
- type_id: 'nvic_57b5eef3774cc60acaede6f5b8bddc67'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'NVIC'
- config_sets:
  - nvic:
    - interrupt_table:
      - 0: []
      - 1: []
      - 2: []
      - 3: []
    - interrupts: []
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */

/* Empty initialization function (commented out)
static void NVIC_init(void) {
} */

/***********************************************************************************************************************
 * LPSPI1 initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'LPSPI1'
- type: 'lpspi'
- mode: 'freertos'
- custom_name_enabled: 'false'
- type_id: 'lpspi_6e21a1e0a09f0a012d683c4f91752db8'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'LPSPI1'
- config_sets:
  - transfer:
    - config:
      - transmitBuffer:
        - init: 'false'
      - receiveBuffer:
        - init: 'false'
      - dataSize: '10'
      - enableTransferStruct: 'defined'
      - flags: ''
  - main:
    - mode: 'kLPSPI_Master'
    - clockSource: 'LpspiClock'
    - clockSourceFreq: 'BOARD_BootClockRUN'
    - master:
      - baudRate: '2000000'
      - bitsPerFrame: '8'
      - cpol: 'kLPSPI_ClockPolarityActiveHigh'
      - cpha: 'kLPSPI_ClockPhaseSecondEdge'
      - direction: 'kLPSPI_MsbFirst'
      - pcsToSckDelayInNanoSec: '1000'
      - lastSckToPcsDelayInNanoSec: '1000'
      - betweenTransferDelayInNanoSec: '1000'
      - whichPcs: 'kLPSPI_Pcs0'
      - pcsActiveHighOrLow: 'kLPSPI_PcsActiveLow'
      - pinCfg: 'kLPSPI_SdiInSdoOut'
      - dataOutConfig: 'kLpspiDataOutRetained'
    - interrupt_priority:
      - IRQn: 'LPSPI1_IRQn'
      - enable_priority: 'true'
      - priority: '5'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */
const lpspi_master_config_t LPSPI1_config = {
  .baudRate = 2000000UL,
  .bitsPerFrame = 8UL,
  .cpol = kLPSPI_ClockPolarityActiveHigh,
  .cpha = kLPSPI_ClockPhaseSecondEdge,
  .direction = kLPSPI_MsbFirst,
  .pcsToSckDelayInNanoSec = 1000UL,
  .lastSckToPcsDelayInNanoSec = 1000UL,
  .betweenTransferDelayInNanoSec = 1000UL,
  .whichPcs = kLPSPI_Pcs0,
  .pcsActiveHighOrLow = kLPSPI_PcsActiveLow,
  .pinCfg = kLPSPI_SdiInSdoOut,
  .dataOutConfig = kLpspiDataOutRetained
};
lpspi_transfer_t LPSPI1_transfer = {
  .txData = NULL,
  .rxData = NULL,
  .dataSize = 10,
  .configFlags = 0
};
lpspi_rtos_handle_t LPSPI1_handle;

static void LPSPI1_init(void) {
  /* Interrupt vector LPSPI1_IRQn priority settings in the NVIC. */
  NVIC_SetPriority(LPSPI1_IRQN, LPSPI1_IRQ_PRIORITY);
  LPSPI_RTOS_Init(&LPSPI1_handle, LPSPI1_PERIPHERAL, &LPSPI1_config, LPSPI1_CLOCK_FREQ);
}

/***********************************************************************************************************************
 * LPUART0 initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'LPUART0'
- type: 'lpuart'
- mode: 'freertos'
- custom_name_enabled: 'false'
- type_id: 'lpuart_54a65a580e3462acdbacefd5299e0cac'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'LPUART0'
- config_sets:
  - fsl_lpuart_freertos:
    - lpuart_rtos_configuration:
      - clockSource: 'LpuartClock'
      - srcclk: 'BOARD_BootClockRUN'
      - baudrate: '38400'
      - parity: 'kLPUART_ParityDisabled'
      - stopbits: 'kLPUART_OneStopBit'
      - buffer_size: '256'
      - enableRxRTS: 'false'
      - enableTxCTS: 'false'
      - txCtsSource: 'kLPUART_CtsSourcePin'
      - txCtsConfig: 'kLPUART_CtsSampleAtStart'
    - interrupt_rx:
      - IRQn: 'LPUART0_RX_IRQn'
      - enable_priority: 'true'
      - priority: '4'
    - interrupt_tx:
      - IRQn: 'LPUART0_TX_IRQn'
      - enable_priority: 'true'
      - priority: '4'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */
lpuart_rtos_handle_t LPUART0_rtos_handle;
lpuart_handle_t LPUART0_lpuart_handle;
uint8_t LPUART0_background_buffer[LPUART0_BACKGROUND_BUFFER_SIZE];
lpuart_rtos_config_t LPUART0_rtos_config = {
  .base = LPUART0_PERIPHERAL,
  .baudrate = 38400UL,
  .srcclk = 12000000UL,
  .parity = kLPUART_ParityDisabled,
  .stopbits = kLPUART_OneStopBit,
  .buffer = LPUART0_background_buffer,
  .buffer_size = LPUART0_BACKGROUND_BUFFER_SIZE,
  .enableRxRTS = false,
  .enableTxCTS = false,
  .txCtsSource = kLPUART_CtsSourcePin,
  .txCtsConfig = kLPUART_CtsSampleAtStart,
};

static void LPUART0_init(void) {
  /* LPUART rtos initialization */
  LPUART_RTOS_Init(&LPUART0_rtos_handle, &LPUART0_lpuart_handle, &LPUART0_rtos_config);
  /* Interrupt vector LPUART0_RX_IRQn priority settings in the NVIC. */
  NVIC_SetPriority(LPUART0_SERIAL_RX_IRQN, LPUART0_SERIAL_RX_IRQ_PRIORITY);
  /* Interrupt vector LPUART0_TX_IRQn priority settings in the NVIC. */
  NVIC_SetPriority(LPUART0_SERIAL_TX_IRQN, LPUART0_SERIAL_TX_IRQ_PRIORITY);
}

/***********************************************************************************************************************
 * Initialization functions
 **********************************************************************************************************************/
void BOARD_InitPeripherals(void)
{
  /* Global initialization */
  DMAMUX_Init(DMA_DMAMUX_BASEADDR);
  EDMA_Init(DMA_DMA_BASEADDR, &DMA_config);

  /* Initialize components */
  CAN0_init();
  LPSPI0_init();
  LPSPI1_init();
  LPUART0_init();
}

/***********************************************************************************************************************
 * BOARD_InitBootPeripherals function
 **********************************************************************************************************************/
void BOARD_InitBootPeripherals(void)
{
  BOARD_InitPeripherals();
}
