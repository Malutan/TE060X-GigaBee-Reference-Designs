
 PARAMETER VERSION = 2.2.0


BEGIN OS
 PARAMETER OS_NAME = xilkernel
 PARAMETER OS_VER = 5.00.a
 PARAMETER PROC_INSTANCE = microblaze_0
 PARAMETER STDIN = debug_module
 PARAMETER STDOUT = debug_module
 PARAMETER SYSINTC_SPEC = microblaze_0_intc
 PARAMETER PTHREAD_STACK_SIZE = 32768
 PARAMETER CONFIG_PTHREAD_MUTEX = true
 PARAMETER CONFIG_TIME = true
 PARAMETER MAX_TMRS = 50
 PARAMETER CONFIG_SEMA = true
 PARAMETER MAX_SEM = 50
 PARAMETER MAX_SEM_WAITQ = 20
 PARAMETER ENHANCED_FEATURES = true
 PARAMETER CONFIG_YIELD = true
 PARAMETER SYSTMR_SPEC = true
 PARAMETER SYSTMR_DEV = axi_timer_0
 PARAMETER SYSTMR_FREQ = 50000000
 PARAMETER SYSTMR_INTERVAL = 1
 PARAMETER SCHED_TYPE = SCHED_PRIO
 PARAMETER MAX_PTHREADS = 8
 PARAMETER MAX_PTHREAD_MUTEX = 50
 PARAMETER MAX_PTHREAD_MUTEX_WAITQ = 20
 PARAMETER MAX_READYQ = 8
 PARAMETER STATIC_PTHREAD_TABLE = ((main_thread,1))
END


BEGIN PROCESSOR
 PARAMETER DRIVER_NAME = cpu
 PARAMETER DRIVER_VER = 1.13.a
 PARAMETER HW_INSTANCE = microblaze_0
END


BEGIN DRIVER
 PARAMETER DRIVER_NAME = gpio
 PARAMETER DRIVER_VER = 3.00.a
 PARAMETER HW_INSTANCE = DIP_Switches_4Bits
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = emaclite
 PARAMETER DRIVER_VER = 3.01.a
 PARAMETER HW_INSTANCE = Ethernet_Lite
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = gpio
 PARAMETER DRIVER_VER = 3.00.a
 PARAMETER HW_INSTANCE = LEDs_4Bits
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = s6_ddrx
 PARAMETER DRIVER_VER = 1.00.a
 PARAMETER HW_INSTANCE = MCB_DDR3
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = gpio
 PARAMETER DRIVER_VER = 3.00.a
 PARAMETER HW_INSTANCE = Push_Buttons_4Bits
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = uartlite
 PARAMETER DRIVER_VER = 2.00.a
 PARAMETER HW_INSTANCE = RS232_Uart_1
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = tmrctr
 PARAMETER DRIVER_VER = 2.03.a
 PARAMETER HW_INSTANCE = axi_timer_0
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = uartlite
 PARAMETER DRIVER_VER = 2.00.a
 PARAMETER HW_INSTANCE = debug_module
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = bram
 PARAMETER DRIVER_VER = 3.00.a
 PARAMETER HW_INSTANCE = microblaze_0_d_bram_ctrl
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = bram
 PARAMETER DRIVER_VER = 3.00.a
 PARAMETER HW_INSTANCE = microblaze_0_i_bram_ctrl
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = intc
 PARAMETER DRIVER_VER = 2.02.a
 PARAMETER HW_INSTANCE = microblaze_0_intc
END


BEGIN LIBRARY
 PARAMETER LIBRARY_NAME = lwip130
 PARAMETER LIBRARY_VER = 3.01.a
 PARAMETER PROC_INSTANCE = microblaze_0
 PARAMETER API_MODE = SOCKET_API
 PARAMETER TCP_WND = 8192
 PARAMETER N_TX_DESCRIPTORS = 0
 PARAMETER N_RX_DESCRIPTORS = 0
 PARAMETER MEMP_N_TCP_PCB = 4
 PARAMETER MEMP_N_TCP_PCB_LISTEN = 1
 PARAMETER IP_FORWARD = 1
 PARAMETER IP_OPTIONS = 1
 PARAMETER ARP_QUEUEING = 0
 PARAMETER MEM_SIZE = 16777216
 PARAMETER PHY_LINK_SPEED = CONFIG_LINKSPEED100
END

BEGIN LIBRARY
 PARAMETER LIBRARY_NAME = xilmfs
 PARAMETER LIBRARY_VER = 1.00.a
 PARAMETER PROC_INSTANCE = microblaze_0
 PARAMETER NUMBYTES = 266000
 PARAMETER BASE_ADDRESS = 0xC5000000
 PARAMETER INIT_TYPE = MFSINIT_IMAGE
 PARAMETER NEED_UTILS = true
END

