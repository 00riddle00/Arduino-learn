
// Defines
#define LED_RED_1 13
#define LED_ORANGE_1 12

#define LED_GREEN_1 11
#define LED_GREEN_2 10
#define LED_GREEN_3 9
#define LED_GREEN_4 8
#define LED_GREEN_5 7
#define LED_GREEN_6 6
#define LED_GREEN_7 5
#define LED_GREEN_8 4

#define LED_ORANGE_2 3
#define LED_RED_2 2

#define DELAY 150

// Declare and initialize global variables
int currentLED;
bool directionRight;
bool gameStarted = false;

int player01_button = 0; 
int player02_button = 0;

void setup() {
	// Initialize the serial port
	Serial.begin(9600);
  
	// Define the LEDs as output
	pinMode(LED_GREEN_1, OUTPUT);
	pinMode(LED_GREEN_2, OUTPUT);
	pinMode(LED_GREEN_3, OUTPUT);
	pinMode(LED_GREEN_4, OUTPUT);
	pinMode(LED_GREEN_5, OUTPUT);
	pinMode(LED_GREEN_6, OUTPUT);
	pinMode(LED_GREEN_7, OUTPUT);
	pinMode(LED_GREEN_8, OUTPUT);
}

void loop() {

    while (!gameStarted) {
        player01_button = analogRead(1);
        delay(50);
        player02_button = analogRead(2);
        delay(50);

        if (player01_button) {
            currentLED = LED_GREEN_1;
            directionRight = true;
            gameStarted = true;
            Serial.println("Game started");
			Serial.println("-------------");
        } else if (player02_button) {
            currentLED = LED_GREEN_8;
            directionRight = false;
            gameStarted = true;
            Serial.println("Game started");
			Serial.println("-------------");
        }
    }
    
  	delay(DELAY);
	digitalWrite(currentLED, true);
  
    if (currentLED == LED_ORANGE_2) {
        int time_remaining = 5;

        while (time_remaining--) {
            player02_button = analogRead(2);

            if (player02_button) {
                  break;
            }
            delay(500);          
        }

        if (!player02_button) {
            currentLED = LED_RED_2;
            digitalWrite(currentLED, true);
            Serial.println("Game over!");
            Serial.println("-------------");
            Serial.println("Player01 won.");
            delay(3000);
            gameStarted = false;
        }
    } else if (currentLED == LED_ORANGE_1) {
      	int time_remaining = 5;

        while (time_remaining--) {
            player01_button = analogRead(1);

            if (player01_button) {
                  break;
            }
            delay(500);          
        }

        if (!player01_button) {
            currentLED = LED_RED_1;
            digitalWrite(currentLED, true);
            Serial.println("Game over!");
            Serial.println("-------------");
            Serial.println("Player02 won.");
            delay(3000);
            gameStarted = false;
        }
    }
  
	delay(DELAY);
	digitalWrite(currentLED, false);
 
      
  	if (directionRight) {
        currentLED--;
        
        if (currentLED == LED_ORANGE_2) {
            directionRight = false;
        }
      
    } else {
      	directionRight = false;
      	currentLED++;
      
      	if (currentLED == LED_ORANGE_1) {
        	directionRight = true;
      	}
    }
}
