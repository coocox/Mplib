



/* Section Definitions */ 
SECTIONS 
{ 
        .text : 
        { 
                . = 0;        			 
                *(.text .text.*) 
                
        }
        
        .rodata :
        {
        				
                *(.rodata .rodata*) 
        } 

        .data :
        {  
                *(.data .data.*) 

        }
                
        .got : 
        {
                *(.got .got.*)         		
        }

        /* .bss section which is used for uninitialized data */ 
        .bss : 
        { 

                *(.bss .bss.*) 
                *(COMMON) 
				

        }
		
		.driver_info :
		{
			*(.driver_info .driver_info.*) 
		}
		
		

} 