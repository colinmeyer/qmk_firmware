# bb85

attiny85 defunct breadboard compatible dev board 

Mostly copied from keyboards/anavi/macropad2

* Keyboard Maintainer: 
* Hardware Supported: 
* Hardware Availability: 

**Note**: Due to limited firmware space, a _**lot**_ of features have to be disabled to get a functioning QMK based keyboard.

Make example for this keyboard (after setting up your build environment):

    make bbtiny:default

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Flashing
### Prerequisites

```bash
git clone https://github.com/micronucleus/micronucleus.git
cd micronucleus/commandline/
sudo make install
```

On GNU/Linux distributions, you will need proper privileges to access the MCU. You can either use `sudo` when flashing firmware, or place [these files](https://github.com/micronucleus/micronucleus/blob/master/commandline/49-micronucleus.rules) in /etc/udev/rules.d/. Once added run the following:

```bash
sudo udevadm control --reload-rules
sudo udevadm trigger
```

### Instructions

* Run one of the following commands:

```bash
make bbtiny:default:flash

# or directly with...
micronucleus --run <firmware.hex>
```

* Plug bbtiny to the USB port and the flashing procedure should start

### Recovery

* [Original Firmware](wwwut)
* [Bootloader Repair](micronucleus)
