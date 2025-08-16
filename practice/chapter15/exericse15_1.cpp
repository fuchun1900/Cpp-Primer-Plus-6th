# include "tv.h"

int main() {
    Tv television; // Create a Tv object
    Remote remote; // Create a Remote object

    // Display initial settings
    television.settings();

    // Turn on the TV
    remote.onoff(television);
    std::cout << "After turning on the TV:\n";
    television.settings();

    // Change volume
    remote.volup(television);
    std::cout << "After increasing volume:\n";
    television.settings();

    // Change channel
    remote.set_chan(television, 5);
    std::cout << "After changing channel to 5:\n";
    television.settings();

    // Set mode to Antenna
    remote.set_mode(television);
    std::cout << "After setting mode to Antenna:\n";
    television.settings();

    // Set input to DVD
    remote.set_input(television);
    std::cout << "After setting input to DVD:\n";
    television.settings();

    // Toggle remote mode
    television.setRmode(remote);
    std::cout << "Remote mode toggled.\n" << "Current remote mode: "
              << (remote.show_mode() == Remote::Normal ? "Normal" : "InterActive") << "\n";

    return 0;
}