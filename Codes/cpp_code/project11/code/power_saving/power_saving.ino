//----------------------------------------------
// coursework p00602 2012
// Peter Haban
// power saving example
// version 1.0 - coursework demonstration
//----------------------------------------------

// we'll use this sketch to see the difference between regular sleep and sleep based on the nacroleptic library

#include <Narcoleptic.h>

void setup() {
}

void loop() {
  

  Narcoleptic.delay(5000); //this will sleep for 2500ms under sleep conditions as provided by the nacroleptic library

  delay(5000); //this will sleep for 2500ms under regular sleep conditions as provided by the delay command
}
