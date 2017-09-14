# MANETSIP

This is a project exploring efficiency and security issues in the implementation of (P2P) SIP over a Mobile Ad-Hoc Network.

The code in this repository is for the OMNET++ simulator and has dependencies on the projects Oversim and inetmanet.

To install and use:
- install OMNET++ version 4.6 (see omnetpp.org where the software and install guide can be found).
- clone projects inetmanet-2.0 and oversim MANETSIP in your working directory:
  ```shell
  git clone https://github.com/NMAI-lab/inetmanet-2.0
  git clone https://github.com/NMAI-lab/Oversim-20121206
  git clone https://github.com/NMAI-lab/MANETSIP
  ```
- import all three projects (file>import>general>existing projects into workspace) from the OMNET++ IDE.
- compile inetmanet (project > build project) then oversim, then MANETSIP (warning: it's slow, particularly for oversim).
  - you might need to fix some settings beforehand for that to work: with the MANETSIP project open, go to Project > Properties > OMNeT++ > Makemake and make sure that the MANETSIP folder is set to build with a custom makefile and that the src folder uses Makemake.
- explore the `.ini` files in MANETSIP/simulations to see the available simulations.
