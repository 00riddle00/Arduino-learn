
// Globals
//
// volatile tells the compiler that the variable might
// change outside the main execution thread, which it 
// does in the ISR (which the compiler doesn't see), 
// so that the compiler won't optimize out parts of
// our code with that variable.
//
// global variable to count the number of overflows
volatile uint8_t tot_overflow;

// initialize timer0, interrupt and variable
// -------------------------------------------
// Flash green LED every 50ms
//
// We use a Timer0 prescaler to reduce a high fequency 
// electrical signal to a lower frequency by integer division
//
// We use an interrupt every time the Timer0 overflows
//
void timer0_init()
{
    // set up timer with prescaler = 256
    TCCR0B |= (1 << CS02);
    
    // initialize counter
    TCNT0 = 0;
    
    // enable overflow interrupt
    TIMSK0 |= (1 << TOIE0);
    
    // enable global interrupts
    sei();
    
    // initialize overflow counter variable
    tot_overflow = 0;
}

// initialize timer1, interrupt and variable
// -------------------------------------------
// Flash blue LED every 1s
//
// We use a Timer1 prescaler to reduce a high fequency 
// electrical signal to a lower frequency by integer division
//
// We use Clear Timer on Compare (CTC) mode
//
// We use Interrupts with CTC mode
//
void timer1_init()
{
    // set up timer with prescaler = 256 and CTC mode
    TCCR1B |= (1 << WGM12)|(1 << CS12);
    
    // initialize counter
    TCNT1 = 0;
    
    // initialize compare value
    OCR1A = 62500;
    
    // enable compare interrupt
    TIMSK1 |= (1 << OCIE1A);
}

// initialize timer2
// -------------------------------------------
// Flash red LED every 16ms
//
// We use a Timer0 prescaler to reduce a high fequency 
// electrical signal to a lower frequency by integer division
//
// We use Clear Timer on Compare (CTC) mode
//
// We use Hardware CTC Mode without interrupts
//
void timer2_init()
{   
    // set up timer OC2A pin in toggle mode and CTC mode
    TCCR2A |= (1 << COM2A0)|(1 << WGM21);
    // set up timer with prescaler = 1024 
    TCCR2B |= (1 << CS22)|(1 << CS21)|(1 << CS20);
    // initialize counter
    TCNT2 = 0;
    // initialize compare value
    OCR2A = 250;
}

        

// TIMER0 overflow interrupt service routine
// called whenever TCNT0 overflows
ISR(TIMER0_OVF_vect)
{
    // keep a track of number of overflows
    tot_overflow++;
}

// this ISR is fired whenever a match occurs
// hence, toggle led here itself..
ISR (TIMER1_COMPA_vect)
{
    // toggle led here
    PORTC ^= (1 << 1);
}

int main(void)
{
    // connect 1 (green) led to pin PB0
    DDRB |= (1 << 0);

    // connect 2 (blue) led to pin PC1
    DDRC |= (1 << 1);

    // connect 3 (red) led to pin PB3 (OC2A)
    DDRB |= (1 << 3);
                
    // initialize timer0
    timer0_init();

    // initialize timer1
    timer1_init();

    // initialize timer2
    timer2_init();
    
    // loop forever
    while(1)
    {
        // check if no. of overflows = 12
        // If the Timer0 has overflown 12 times,
        // 12 * 4.096ms = 49.152ms would have passed.
        //
        // In the 13th iteration, we need a delay of 50ms - 49.152ms = 0.848ms.
        //
        // Thus, in the 13th iteration, we only allow the timer
        // to count up to 53, and then reset it
        //
        if (tot_overflow >= 12)  // NOTE: '>=' is used
        {
            // check if the timer count reaches 53
            if (TCNT0 >= 53)
            {
                PORTB ^= (1 << 0);    // toggles the led
                TCNT0 = 0;            // reset counter
                tot_overflow = 0;     // reset overflow counter
            }
        }
    }
}
