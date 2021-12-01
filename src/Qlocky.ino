// STARRY HORIZON for Watchy by SQFMI
// Copyright 2021 Dan Delany dan.delany@gmail.com
// Released under free MIT License : https://github.com/dandelany/watchy-faces/blob/main/LICENSE

#ifndef QLOCK_C
#define QLOCK_C
#include "Qlock.h"
#endif

Qlock face; //instantiate watchface

void setup() {
	Serial.begin(9600);
  face.init(); //call init in setup
}

void loop() {
  // this should never run, Watchy deep sleeps after init();
}
