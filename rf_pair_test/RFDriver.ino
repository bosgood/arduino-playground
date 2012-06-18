// Maurice Ribble 
// 8-30-2009
// http://www.glacialwanderer.com/hobbyrobotics
// Used Arduino 0017
// This does does some error checking to try to make sure the receiver on this one way RF 
//  serial link doesn't repond to garbage

#define NETWORK_SIG_SIZE 3

#define VAL_SIZE         2
#define CHECKSUM_SIZE    1
#define PACKET_SIZE      (NETWORK_SIG_SIZE + VAL_SIZE + CHECKSUM_SIZE)

// The network address byte and can be change if you want to run different devices in proximity to each other without interfearance
#define NET_ADDR 5

const byte g_network_sig[NETWORK_SIG_SIZE] = {0x8F, 0xAA, NET_ADDR};  // Few bytes used to initiate a transfer

// Sends an unsigned int over the RF network
void writeUInt(SoftwareSerial sserial, unsigned int val)
{
  byte checksum = (val/256) ^ (val&0xFF);
  sserial.write(0xF0);  // This gets reciever in sync with transmitter
  sserial.write(g_network_sig, NETWORK_SIG_SIZE);
  sserial.write((byte*)&val, VAL_SIZE);
  sserial.write(checksum); //CHECKSUM_SIZE
}

// Receives an unsigned int over the RF network
unsigned int readUInt(SoftwareSerial sserial, bool wait)
{
  int pos = 0;          // Position in the network signature
  unsigned int val;     // Value of the unsigned int
  byte c = 0;           // Current byte
  
  if((sserial.available() < PACKET_SIZE) && (wait == false))
  {
    return 0xFFFF;
  }
  
  while(pos < NETWORK_SIG_SIZE)
  { 
    while(sserial.available() == 0); // Wait until something is avalible
    c = sserial.read();

    if (c == g_network_sig[pos])
    {
      if (pos == NETWORK_SIG_SIZE-1)
      {
        byte checksum;

        while(sserial.available() < VAL_SIZE + CHECKSUM_SIZE); // Wait until something is avalible
        val      =  sserial.read();
        val      += ((unsigned int)sserial.read())*256;
        checksum =  sserial.read();
        
        if (checksum != ((val/256) ^ (val&0xFF)))
        {
          // Checksum failed
          pos = -1;
        }
      }
      ++pos;
    }
    else if (c == g_network_sig[0])
    {
      pos = 1;
    }
    else
    {
      pos = 0;
      if (!wait)
      {
        return 0xFFFF;
      }
    }
  }
  return val;
}
