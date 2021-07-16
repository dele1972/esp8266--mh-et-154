# esp8266--mh-et-154
Test my MH-ET 1.54 ePaper mini GxEPD configuration


## Compiler Messages

```Text
Executable segment sizes:
IROM   : 247944          - code in flash         (default or ICACHE_FLASH_ATTR) 
IRAM   : 28172   / 32768 - code in IRAM          (ICACHE_RAM_ATTR, ISRs...) 
DATA   : 1248  )         - initialized variables (global, static) in RAM/HEAP 
RODATA : 1232  ) / 81920 - constants             (global, static) in RAM/HEAP 
BSS    : 35656 )         - zeroed variables      (global, static) in RAM/HEAP 
Sketch uses 278596 bytes (26%) of program storage space. Maximum is 1044464 bytes.
Global variables use 38136 bytes (46%) of dynamic memory, leaving 43784 bytes for local variables. Maximum is 81920 bytes.
esptool.py v2.8
Serial port /dev/ttyUSB0
Connecting....
Chip is ESP8266EX
Features: WiFi
Crystal is 26MHz
MAC: XX:XX:XX:XX:XX:XX
Uploading stub...
Running stub...
Stub running...
Configuring flash size...
Auto-detected Flash size: 4MB
Compressed 282752 bytes to 207173...
Wrote 282752 bytes (207173 compressed) at 0x00000000 in 18.3 seconds (effective 123.4 kbit/s)...
Hash of data verified.

Leaving...
Hard resetting via RTS pin...
```

## My Serial Monitor Output

```text
STARTS WITH A STRANGE GARBISHED LINE
20:27:58.682 -> Heap after DISPLAY INIT: 39272
20:27:58.682 -> 
20:27:58.682 -> 
20:27:58.682 -> Heap before drawPaged(): 39272
20:27:58.715 -> Power On : 10680

20:28:01.275 -> scandone
20:28:01.275 -> state: 0 -> 2 (b0)
20:28:01.707 -> state: 2 -> 3 (0)
20:28:01.707 -> state: 3 -> 5 (10)
20:28:01.707 -> add 0
20:28:01.707 -> aid 1
20:28:01.707 -> cnt 
20:28:01.740 -> 
20:28:01.740 -> connected with SSID-NAME, channel 1
20:28:01.740 -> dhcp client start...
20:28:04.799 -> ip:xxx.xxx.xxx.xxx,mask:xxx.xxx.xxx.xxx,gw:xxx.xxx.xxx.xxx
20:28:07.756 -> drawPaged : 7222654

20:28:09.252 -> Heap after drawPaged(): 38464
20:28:09.252 -> 
20:28:09.252 -> 
20:28:09.252 -> End of Script
```

## Links

- Great Tutorial: [Adafruit GFX Graphics Library](https://learn.adafruit.com/adafruit-gfx-graphics-library?view=all) by Phillip Burgess
- Github: [Adafruit GFX Library](https://github.com/adafruit/Adafruit-GFX-Library)
- Github: [GxEPD](https://github.com/ZinggJM/GxEPD)
- German Tutorial for GxEPD: [E-Paper Display am ESP32 und ESP8266 - [Teil1]](https://www.az-delivery.de/blogs/azdelivery-blog-fur-arduino-und-raspberry-pi/e-paper-display-am-esp32-und-esp8266-teil1)

## Others

- Github: [EPD](https://github.com/asukiaaa/EPD)
  - I could not get my ePaper display to work with this library
- [E-Paper + ESP8266 Tutorial - Easy Text & Images](https://youtu.be/0IuqL-4UftA)
  - by Kevin Darrah (17.08.2018)
  - he made slight changes in the libs for memory optimizations - a blurprint for my project?
    - wifi stat + wifi ap + wifisecure + https post
