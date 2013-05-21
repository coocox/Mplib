This demo is an example which introduces how to use flash driver and user boot mode.

Operation procedure:

1)Open Keil uVision, connect ULink2 with PC and board, then click menu: Project->Open project, choose 

  "Flash_Userboot.uvproj" to open demo project.

2)Click menu: Flash->Erase to erase entire chip.

3)Click menu: Project->Rebuild all target files, then copy file "Flash_Userboot\KEIL\res\A\Flash_Userboot.axf"

  to folder "Flash_Userboot\KEIL\obj", choose "YES" to replace the existed file.
 
4)Click menu: Flash->Download, then Keil will use its embedded flashloader to load DemoA to board.

5)Repeat 3) and 4), copy file "Flash_Userboot\KEIL\res\B\Flash_Userboot.axf" to folder "Flash_Userboot\KEIL\obj" 

  to replace the existed file again, and then download DemoB to board.

6)Click menu: Project->Rebuild all target files, then click menu: Flash->Download to download application 

  "Flash_Userboot" to board.

7)Press RESET button, DemoA will run first.

8)Press RESET button while SW0 is turned on, and don't release SW0 until LCD displays "User Boot Mode".
  After a while, LCD displays "Finished Restart...", then system will reset automatically to run DemoB (LED1 is blinking, LCD displays "DEMO B").

Note: NO LCD dispaly for M365 

