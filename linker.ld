ENTRY(_start)

MEMORY
{
	ram : ORIGIN = 0x80000000, LENGTH = 1M
}


SECTIONS
{
	.text : 
	{
		*(.text .text.*)
	} > ram
	
	.data :
	{
		*(.data .data.*)
	} > ram
	
	.rodata : 
	{
		*(.rodata .rodata.*)
	} >ram

	.bss : 
	{
		*(.bss .bss.*)
	} > ram
	
	.stack :
	{
		. = . + 1024;
		endstack = . ;
	} >ram
		
		
}