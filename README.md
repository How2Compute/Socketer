# Socketer
A TCP socket blueprint library for Unreal Engine 4 - NOW WITH SUPPORT FOR Unreal Engine 4.22!

## How do I install Socketer?
To install Socketer, head to [releases](https://github.com/How2Compute/Socketer/releases), and download the latest (pre-compiled) copy for your engine version. Now head to where your engine is installed (likely C:/Program Files/Epic Games/UE_4.21), and open up Engine/Plugins. I recommend creating a folder to house downloaded plugins, so why not create one named "Downloaded"? Once you've created this folder, copy the Socketer-UExxx directory over from your zip file. Once you've done this, rename it to "Socketer", and you're set! You may need to restart Unreal Engine for the plugin to be detected.

## How do I enable Socketer?
Once you've installed Socketer, open up your project, and head to Edit -> Plugins. Now find the Networking category, and search for Socketer. Once you've found it, press the enabled checkbox, and restart your project. Socketer should now be installed and enabled in your project!

## Where do I find out more?
Please view the following Unreal Engine Forum thread: [https://forums.unrealengine.com/community/community-content-tools-and-tutorials/112836-socketer-free-tcp-socket-blueprint-plugin](https://forums.unrealengine.com/community/community-content-tools-and-tutorials/112836-socketer-free-tcp-socket-blueprint-plugin)

## Where do I report issues?
To report an issue, please head to this project's [GitHub issues page](https://github.com/How2Compute/Socketer/issues). You can also use the forum thread.

# Word of warning
Socketer is an older project, and was designed as a one-to-one implementation of the FSocket interface (or atleast, the relevant & TCP parts of it). This means that you should be aware of how sockets work, and be careful to close your sockets, and check if there is any data available before trying to read it. Not taking these precautions, can lead to hangs, crashes, and other unexpected/undeired behavior in your game. With that out of the way - you are free to open up an issue or Pull Request with any improvement/issues!

# Need Secured Sockets (SSL/TLS), Hashing, Encryption & More?
Please consider checking out [NetShield](https://www.unrealengine.com/marketplace/netshield), our Unreal Engine 4 plugin that provides all of the above, and more!
