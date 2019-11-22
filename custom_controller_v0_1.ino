#include <MIDI.h>

MIDI_CREATE_DEFAULT_INSTANCE();

int buttonApin = 13; // footswitch A
int buttonBpin = 12; // footswitch B
int buttonCpin = 11; // footswitch C
int buttonDpin = 10; // footswitch D
int buttonEpin = 9; // footswitch E

int analogPot1 = A0; // knob 1
int analogPot2 = A1; // knob 2
int analogpot1Old = 0; // initialize pots
int analogpot2Old = 0;

#define analogpot1CC 54
#define analogpot2CC 54

void setup() {
    MIDI.begin();

    pinMode(buttonApin, INPUT_PULLUP);
    pinMode(buttonBpin, INPUT_PULLUP);
    pinMode(buttonCpin, INPUT_PULLUP);
    pinMode(buttonDpin, INPUT_PULLUP);
    pinMode(buttonEpin, INPUT_PULLUP);

    pinMode(analogPot1, INPUT);
    pinMode(analogPot2, INPUT);

    Serial.begin(9600);
}

void loop() {
    static bool buttonAvalueOld = HIGH;
    bool buttonAvalueNew = digitalRead(buttonApin);

    if(buttonAvalueNew != buttonAvalueOld) {
        if(buttonAvalueNew != LOW) {
            MIDI.sendNoteOn(60, 127, 1);
            Serial.println("Note C On");
        }
        else {
            MIDI.sendNoteOff(60, 0, 1);
            Serial.println("Note C Off");
        }
    buttonAvalueOld = buttonAvalueNew;
    }
    static bool buttonBvalueOld = HIGH;
    bool buttonBvalueNew = digitalRead(buttonBpin);

    if(buttonBvalueNew != buttonBvalueOld) {
        if(buttonBvalueNew != LOW) {
            MIDI.sendNoteOn(62, 127, 1);
            Serial.println("Note D On");
        }
        else {
            MIDI.sendNoteOff(62, 0, 1);
            Serial.println("Note D Off");
        }
    buttonBvalueOld = buttonBvalueNew;
    }
    static bool buttonCvalueOld = HIGH;
    bool buttonCvalueNew = digitalRead(buttonCpin);

    if(buttonCvalueNew != buttonCvalueOld) {
        if(buttonCvalueNew != LOW) {
            MIDI.sendNoteOn(64, 127, 1);
            Serial.println("Note E On");
        }
        else {
            MIDI.sendNoteOff(64, 0, 1);
            Serial.println("Note E Off");
        }
    buttonCvalueOld = buttonCvalueNew;
    }
    static bool buttonDvalueOld = HIGH;
    bool buttonDvalueNew = digitalRead(buttonDpin);

    if(buttonDvalueNew != buttonDvalueOld) {
        if(buttonDvalueNew != LOW) {
            MIDI.sendNoteOn(65, 127, 1);
            Serial.println("Note F On");
        }
        else {
            MIDI.sendNoteOff(65, 0, 1);
            Serial.println("Note F Off");
        }
    buttonDvalueOld = buttonDvalueNew;
    }
    static bool buttonEvalueOld = HIGH;
    bool buttonEvalueNew = digitalRead(buttonEpin);

    if(buttonEvalueNew != buttonEvalueOld) {
        if(buttonEvalueNew != LOW) {
            MIDI.sendNoteOn(67, 127, 1);
            Serial.println("Note G On");
        }
        else {
            MIDI.sendNoteOff(67, 0, 1);
            Serial.println("Note G Off");
        }
    buttonEvalueOld = buttonEvalueNew;
    }

    int pot1 = analogRead(A0);
    int analogpot1New = analogRead(A0);

    if(analogpot1New - analogpot1Old >= 35 || analogpot1Old - analogpot1New >= 35) {
        analogpot1New = (map(analogpot1New, 1023, 0, 0, 120));
        analogpot1New = (constrain(analogpot1New, 0, 120));
        MIDI.sendControlChange(analogpot1CC, analogpot1New, 1);
        Serial.print("pot: ");
        Serial.println(pot1);
        Serial.print("potread: ");
        Serial.println(analogpot1New);
    }
    int pot2 = analogRead(A1);
    int analogpot2New = analogRead(A1);

    if(analogpot2New - analogpot2Old >= 35 || analogpot2Old - analogpot2New >= 35) {
        analogpot2New = (map(analogpot2New, 1023, 0, 0, 120));
        analogpot2New = (constrain(analogpot2New, 0, 120));
        MIDI.sendControlChange(analogpot2CC, analogpot2New, 1);
        Serial.print("pot: ");
        Serial.println(pot2);
        Serial.print("potread: ");
        Serial.println(analogpot2New);
    }
    delay(25);
}
