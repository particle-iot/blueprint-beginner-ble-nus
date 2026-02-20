#include "Particle.h"
 
SYSTEM_MODE(AUTOMATIC);
 
static const BleUuid NUS_SERVICE_UUID("6E400001-B5A3-F393-E0A9-E50E24DCCA9E");
static const BleUuid NUS_RX_UUID("6E400002-B5A3-F393-E0A9-E50E24DCCA9E"); // central -> peripheral
static const BleUuid NUS_TX_UUID("6E400003-B5A3-F393-E0A9-E50E24DCCA9E"); // peripheral -> central
 
void onNusRx(const uint8_t *data, size_t len, const BlePeerDevice &peer, void *context)
{
  (void)peer;
  (void)context;
  Serial.printf("NUS RX (%u bytes): ", (unsigned)len);
  Serial.write(data, len);
  Serial.println();
}
 
// TX characteristic (notify)
BleCharacteristic nusTx(
    "tx",
    BleCharacteristicProperty::NOTIFY,
    NUS_TX_UUID,
    NUS_SERVICE_UUID);
 
// RX characteristic (write)
BleCharacteristic nusRx(
    "rx",
    BleCharacteristicProperty::WRITE | BleCharacteristicProperty::WRITE_WO_RSP,
    NUS_RX_UUID,
    NUS_SERVICE_UUID,
    onNusRx,
    nullptr);
 
void setup()
{
  Serial.begin(115200);
 
  BLE.on();
  BLE.setDeviceName("Particle-NUS");
 
  BLE.addCharacteristic(nusTx);
  BLE.addCharacteristic(nusRx);
 
  // Advertise the NUS service UUID so scanners can find it
  BleAdvertisingData adv;
  adv.appendLocalName("Particle-NUS");
  adv.appendServiceUUID(NUS_SERVICE_UUID);
 
  BLE.advertise(&adv);
}
 
void loop()
{
  static unsigned long last = 0;
  if (millis() - last < 1000)
    return;
  last = millis();
 
  if (!BLE.connected())
    return;
 
  // For NOTIFY characteristics, updating the value triggers notifications
  // to subscribed centrals.
  Log.info("Updating NUS TX characteristic value");
  nusTx.setValue("hello from Particle over NUS\n");
}