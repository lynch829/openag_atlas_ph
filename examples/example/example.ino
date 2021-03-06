#include <openag_atlas_ph.h>

AtlasPh atlas_ph_1(99);

void setup() {
  Serial.begin(9600);
  atlas_ph_1.begin();
}

std_msgs::Float32 ph_msg;

void loop() {
  atlas_ph_1.update();

  if (atlas_ph_1.get_water_potential_hydrogen(ph_msg)) {
    Serial.print("Potential Hydrogen: ");
    Serial.println(ph_msg.data);
  }
  if (atlas_ph_1.has_error) {
    Serial.print("Error: ");
    Serial.println(atlas_ph_1.error_msg);
    atlas_ph_1.has_error = false;
  }
}
