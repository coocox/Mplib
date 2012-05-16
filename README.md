Manufacture peripheral Library - MPLib, modified by CooCox in order to add to CoIDE(http://www.coocox.org)

https://github.com/coocox/MPLib


General Information
-------------------------------------------------------------------------------

Manufacture peripheral library is a library which is provided by Manufacturer.
CooCox modified the manufacture peripheral library in order to add to CoIDE.
-

Features
-------------------------------------------------------------------------------

- Provided by Manufacturer 
- Almost all the Manufacture peripheral library are based on CMSIS
- It supports GCC\IAR and Keil development environment
- Have at least one example for each peripheral. 
- Have a description document for each peripheral. 
- All the examples have a description document 


Repository Information
-------------------------------------------------------------------------------

The contents of the repository can be divided into 3 parts:
- Manufacture peripheral library source code that based on CMSIS
- Examples for each peripheral.
- Description document for each peripheral.

Contribution

-------------------------------------------------------------------------------

Wish to be a contributor of Manufacture peripheral Library to CoIDE? You can:
1. Add a new Manufacture peripheral Library which CoIDE not support yet.
2. Improve Manufacture peripheral Library and correction bugs
3. Add a new example to the existing library
4. Update Manufacture peripheral Library which CoIDE already supported.
5. Just add a new chip to CoIDE.

Please see the guide in the /Document/.

Repository Layout
-------------------------------------------------------------------------------
       
/Document/
    Some document.
    
/LICENSE
    Licensing and copyright information.
    
/Nuvoton/
    manufacturer library of Nuvoton.
    
    Mini51/
        manufacturer library of Mini51.
		
		cmsis_lib/
		    CMSIS manufacturer library
			
		    lib/
			    cmsis_boot/
				    cmsis boot include startup and CMSIS ARM Device Peripheral Access Layer File
					MINI51 is the name of series
				
				    startup/
					    document/
						    startup.xml
						src/
						    startup_MINI51.c
				    MINI51.h
					system_MINI51.c
					system_MINI51.h
				
				cmsis_core/
				    core_cm0.c
					core_cm0.h
				
				Include/
				    Driver/
					    DrvADC.h
						...
					
					System/
					    ModuleID.h
						...
				
				Source/
					DrvADC.c
					...
						
					    
				
			all/
			    A example project include all the MINI51 manufacturer library files
				
				example/
				
			        ewarm/
				    src/
				    ...
			    ...
			
			acmp/
			    The example of a peripheral 
				
				document/
				    acmp.xml
					description.html
					
				example/
				    SmplAcmp
					    doc/
						    SmplAcmp.xml
						src/
						    SmplAcmp.c
						
						ewarm/
						    SmplAcmp.eww
							SmplAcmp.ewp
			
			...
			
	    config
            device/
	            Chip device file which is used by CoIDE.If you want CoIDE to support a new chip,you can write
		        a file like this.
    	        Mini51LAN.xml
		        Mini51ZAN.xml
		        ...
			
		    debugger/
		        Nuvtonmi51x.xml
			
	    flash/
	        flash algorithm of Mini51
		
	        Mini51_8.elf
		    ...
			
		resource/
		    Somer resources of Mini51
			
			mini51_coide_empty_project/
			
	    coide_gen.bat
		    Use to gen the CoIDE project
		
        ...	
		
	NUC1xx/
    ...
/Holtek/
/ST/
/NXP/	
/TI/

/.../
    a new manufacturer
	
/resource/
    some resources and template.
    
    template/
        manufacturer library of template.
		
		cmsis_lib/
		    CMSIS manufacturer library
			
		    lib/
			    cmsis_boot/
				    cmsis boot include startup and CMSIS ARM Device Peripheral Access Layer File
					$series$ is the name of series
				
				    startup/
					    document/
						    startup.xml
						src/
						    startup_MINI51.c
				    $series$.h
					system_$series$.c
					system_$series$.h
				
				cmsis_core/
				    core_cm0.c
					core_cm0.h
				
				Include/
				    readme.txt
				
				src/
					readme.txt
					...
						
					    
				
			all/
			    A example project include all the MINI51 manufacturer library files
				
				example/
				
			        ewarm/
				    src/
				    ...
			    ...
			
			adc/
			    The example of a peripheral 
				
				document/
				    template.xml
					template.html
					
				example/
				    template
					    doc/
						    template.xml
						src/
						    template.c
						
						ewarm/
						    SamplePrj.eww
							SamplePrj.ewp
			
			...
			
	    config
            device/
	            Chip device file which is used by CoIDE.If you want CoIDE to support a new chip,you can write
		        a file like this.
    	        template.xml
		        ...
			
		    debugger/
		        template.xml
			
	    flash/
	        flash algorithm of template
			
			source/
			    template/
				    gccProject/
					    makefile
						
					FlashAlgoFncs.c
					FlashAlgoInfo.c
					
		    This file is a output file of making the gcc makefile.
	        template.elf
		    ...
			
		resource/
		    Somer resources of template
			
			coide_empty_project/
			
	    coide_gen.bat
		    Use to gen the CoIDE project
		
        ...	
		
	tools/
	    iar2coide/
		    iar2coide.exe
        
/README
    This file.
    
/clean.bat
    clean all the temp files.
        
        
    
    
        
        

