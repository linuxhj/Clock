SET PATH=C:\Keil_v5\ARM\ARMCC\Bin;C:\Program Files (x86)\Common Files\Oracle\Java\javapath;C:\Program Files (x86)\NVIDIA Corporation\PhysX\Common;C:\MentorGraphics\9.3PADS\SDD_HOME\common\win32\bin;C:\MentorGraphics\9.3PADS\SDD_HOME\common\win32\lib;C:\Windows\system32;C:\Windows;C:\Windows\System32\Wbem;C:\Windows\System32\WindowsPowerShell\v1.0\;C:\Windows\System32\OpenSSH\;C:\Cadence\SPB_16.6\tools\pcb\bin;C:\Cadence\SPB_16.6\tools\bin;C:\Cadence\SPB_16.6\tools\libutil\bin;C:\Cadence\SPB_16.6\tools\fet\bin;C:\Cadence\SPB_16.6\tools\specctra\bin;C:\Cadence\SPB_16.6\tools\pspice;C:\Cadence\SPB_16.6\tools\capture;C:\Cadence\SPB_16.6\openaccess\bin\win32\opt;C:\Program Files (x86)\IDM Computer Solutions\UltraEdit;C:\Program Files\TortoiseSVN\bin;C:\Program Files\dotnet\;C:/MentorGraphics/9.3PADS/MGC_HOME.ixn/bin;C:/MentorGraphics/9.3PADS/MGC_HOME.ixn/lib;C:\MentorGraphics\9.3PADS\MGC_HOME.ixn\bin;C:\MentorGraphics\9.3PADS\MGC_HOME.ixn\lib;C:\Program Files (x86)\Windows Kits\8.1\Windows Performance Toolkit\;C:\Program Files\TortoiseGit\bin;C:\Program Files (x86)\Java\jdk1.8.0_71\bin;C:\Program Files (x86)\Java\jdk1.8.0_71\jre\bin;C:\Windows\Microsoft.NET\Framework64\v4.0.30319;C:\Users\windo\AppData\Local\Microsoft\WindowsApps;C:\Users\windo\AppData\Local\Programs\Microsoft VS Code\bin;C:\MentorGraphics\9.3PADS\SDD_HOME\common\win32\lib;C:\Users\windo\AppData\Local\GitHubDesktop\bin
SET CPU_TYPE=STM32F407VGTx
SET CPU_VENDOR=STMicroelectronics
SET UV2_TARGET=LED_Lighting
SET CPU_CLOCK=0x00B71B00
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\main.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\stm32f4xx_hal.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\stm32f4xx_hal_rcc.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmLink" --Via ".\Clock.lnp"
"C:\Keil_v5\ARM\ARMCC\Bin\fromelf.exe" ".\Clock.axf" --i32combined --output ".\Clock.hex"
