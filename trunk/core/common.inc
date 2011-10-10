.macro ACMultiplexed
  cbi     ADCSRA, ADEN          ; disable ADC
  in      temp1, SFIOR
  sbr     temp1, (1<<ACME)      ; switch to comparator multiplexed
  out     SFIOR, temp1
.endmacro  

.macro ACNormal
   cbr  temp1, (1<<ACME)        ; set to AN1
   out  SFIOR, temp1
   sbi  ADCSRA, ADEN            ; enable ADC
.endmacro  

.macro ACChannel 
   ldi   temp1, @0              
   out   ADMUX, temp1
.endmacro  
   
#define RPM_TO_COMM_TIME(x) (1000000 * 10 / x)
#define PWR_PCT_TO_VAL(x)   (x*POWER_RANGE/100)