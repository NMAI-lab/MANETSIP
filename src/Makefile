#
# OMNeT++/OMNEST Makefile for p2psipmanet
#
# This file was generated with the command:
#  opp_makemake -f --deep -I../../Oversim-20121206/src/common -I../../inetmanet-2.0/src/networklayer/common -I../../inetmanet-2.0/src/transport/tcp/queues -I../../inetmanet-2.0/src/linklayer/ieee80211mesh/locator -I../../inetmanet-2.0/src/linklayer/ieee80211/radio/errormodel -I../../inetmanet-2.0/src/world/radio -I../../inetmanet-2.0/src/networklayer/icmpv6 -I../../Oversim-20121206/src/overlay/pastry -I../../inetmanet-2.0/src/networklayer/arp -I../../inetmanet-2.0/src/linklayer/ethernet -I../../Oversim-20121206/src/underlay/singlehostunderlay -I../../inetmanet-2.0/src/networklayer/contract -I../../inetmanet-2.0/src/transport/sctp -I../../Oversim-20121206/src/underlay/simpleunderlay -I../../inetmanet-2.0/src/networklayer/routing/aodv -I../../inetmanet-2.0/src/mobility/contract -I../../inetmanet-2.0/src/transport/udp -I../../inetmanet-2.0/src/transport/tcp -I../../inetmanet-2.0/src/util/headerserializers/ipv6 -I../../inetmanet-2.0/src/world/powercontrol -I../../Oversim-20121206/src/overlay/chord -I../../inetmanet-2.0/src/linklayer/ieee80211/radio -I../../inetmanet-2.0/src/util -I../../inetmanet-2.0/src/networklayer/manetrouting/dsr -I../../inetmanet-2.0/src/util/headerserializers/ipv4 -I../../inetmanet-2.0/src -I../../inetmanet-2.0/src/networklayer/ipv4 -I../../inetmanet-2.0/src/linklayer/radio -I../../inetmanet-2.0/src/wpan/linklayer/ieee802154/mac -I../../inetmanet-2.0/src/world/obstacles -I../../inetmanet-2.0/src/battery/models -I../../inetmanet-2.0/src/wpan/linklayer/ieee802154/contract -I../../inetmanet-2.0/src/linklayer/ieee80211/mac -I../../inetmanet-2.0/src/wpan/linklayer/bmac -I../../inetmanet-2.0/src/linklayer/radio/propagation -I../../inetmanet-2.0/src/networklayer/ipv6tunneling -I../../inetmanet-2.0/src/linklayer/ieee80211/mgmt -I../../inetmanet-2.0/src/networklayer/ipv6 -I../../Oversim-20121206/src/common/cbr -I../../inetmanet-2.0/src/util/headerserializers/tcp -I../../Oversim-20121206/src/common/cbr/globalViewBuilder -I../../inetmanet-2.0/src/mobility/common -I../../inetmanet-2.0/src/util/headerserializers/udp -I../../Oversim-20121206/src/applications/dht -I../../inetmanet-2.0/src/applications/pingapp -I../../inetmanet-2.0/src/util/headerserializers/sctp -I../../inetmanet-2.0/src/linklayer/common -I../../inetmanet-2.0/src/transport/contract -I../../inetmanet-2.0/src/networklayer/autorouting/ipv4 -I../../inetmanet-2.0/src/networklayer/manetrouting/base -I../../inetmanet-2.0/src/transport/tcp_common -I../../inetmanet-2.0/src/linklayer/contract -I../../inetmanet-2.0/src/base -I../../inetmanet-2.0/src/networklayer/xmipv6 -I../../inetmanet-2.0/src/wpan/phyLayer/ieee802154 -I../../inetmanet-2.0/src/status -I../../inetmanet-2.0/src/util/headerserializers -I../../inetmanet-2.0/src/wpan/networklayer/contract -L../../inetmanet-2.0/out/$$\(CONFIGNAME\)/src -L../../Oversim-20121206/out/$$\(CONFIGNAME\)/src -linet -lOversim-20121206 -DINET_IMPORT -KINETMANET_2_0_PROJ=../../inetmanet-2.0 -KOVERSIM_20121206_PROJ=../../Oversim-20121206
#

# Name of target to be created (-o option)
TARGET = p2psipmanet$(EXE_SUFFIX)

# User interface (uncomment one) (-u option)
USERIF_LIBS = $(ALL_ENV_LIBS) # that is, $(TKENV_LIBS) $(CMDENV_LIBS)
#USERIF_LIBS = $(CMDENV_LIBS)
#USERIF_LIBS = $(TKENV_LIBS)

# C++ include paths (with -I)
INCLUDE_PATH = \
    -I../../Oversim-20121206/src/common \
    -I../../inetmanet-2.0/src/networklayer/common \
    -I../../inetmanet-2.0/src/transport/tcp/queues \
    -I../../inetmanet-2.0/src/linklayer/ieee80211mesh/locator \
    -I../../inetmanet-2.0/src/linklayer/ieee80211/radio/errormodel \
    -I../../inetmanet-2.0/src/world/radio \
    -I../../inetmanet-2.0/src/networklayer/icmpv6 \
    -I../../Oversim-20121206/src/overlay/pastry \
    -I../../inetmanet-2.0/src/networklayer/arp \
    -I../../inetmanet-2.0/src/linklayer/ethernet \
    -I../../Oversim-20121206/src/underlay/singlehostunderlay \
    -I../../inetmanet-2.0/src/networklayer/contract \
    -I../../inetmanet-2.0/src/transport/sctp \
    -I../../Oversim-20121206/src/underlay/simpleunderlay \
    -I../../inetmanet-2.0/src/networklayer/routing/aodv \
    -I../../inetmanet-2.0/src/mobility/contract \
    -I../../inetmanet-2.0/src/transport/udp \
    -I../../inetmanet-2.0/src/transport/tcp \
    -I../../inetmanet-2.0/src/util/headerserializers/ipv6 \
    -I../../inetmanet-2.0/src/world/powercontrol \
    -I../../Oversim-20121206/src/overlay/chord \
    -I../../inetmanet-2.0/src/linklayer/ieee80211/radio \
    -I../../inetmanet-2.0/src/util \
    -I../../inetmanet-2.0/src/networklayer/manetrouting/dsr \
    -I../../inetmanet-2.0/src/util/headerserializers/ipv4 \
    -I../../inetmanet-2.0/src \
    -I../../inetmanet-2.0/src/networklayer/ipv4 \
    -I../../inetmanet-2.0/src/linklayer/radio \
    -I../../inetmanet-2.0/src/wpan/linklayer/ieee802154/mac \
    -I../../inetmanet-2.0/src/world/obstacles \
    -I../../inetmanet-2.0/src/battery/models \
    -I../../inetmanet-2.0/src/wpan/linklayer/ieee802154/contract \
    -I../../inetmanet-2.0/src/linklayer/ieee80211/mac \
    -I../../inetmanet-2.0/src/wpan/linklayer/bmac \
    -I../../inetmanet-2.0/src/linklayer/radio/propagation \
    -I../../inetmanet-2.0/src/networklayer/ipv6tunneling \
    -I../../inetmanet-2.0/src/linklayer/ieee80211/mgmt \
    -I../../inetmanet-2.0/src/networklayer/ipv6 \
    -I../../Oversim-20121206/src/common/cbr \
    -I../../inetmanet-2.0/src/util/headerserializers/tcp \
    -I../../Oversim-20121206/src/common/cbr/globalViewBuilder \
    -I../../inetmanet-2.0/src/mobility/common \
    -I../../inetmanet-2.0/src/util/headerserializers/udp \
    -I../../Oversim-20121206/src/applications/dht \
    -I../../inetmanet-2.0/src/applications/pingapp \
    -I../../inetmanet-2.0/src/util/headerserializers/sctp \
    -I../../inetmanet-2.0/src/linklayer/common \
    -I../../inetmanet-2.0/src/transport/contract \
    -I../../inetmanet-2.0/src/networklayer/autorouting/ipv4 \
    -I../../inetmanet-2.0/src/networklayer/manetrouting/base \
    -I../../inetmanet-2.0/src/transport/tcp_common \
    -I../../inetmanet-2.0/src/linklayer/contract \
    -I../../inetmanet-2.0/src/base \
    -I../../inetmanet-2.0/src/networklayer/xmipv6 \
    -I../../inetmanet-2.0/src/wpan/phyLayer/ieee802154 \
    -I../../inetmanet-2.0/src/status \
    -I../../inetmanet-2.0/src/util/headerserializers \
    -I../../inetmanet-2.0/src/wpan/networklayer/contract \
    -I.

# Additional object and library files to link with
EXTRA_OBJS =

# Additional libraries (-L, -l options)
LIBS = -L../../inetmanet-2.0/out/$(CONFIGNAME)/src -L../../Oversim-20121206/out/$(CONFIGNAME)/src  -linet -lOversim-20121206
LIBS += -Wl,-rpath,`abspath ../../inetmanet-2.0/out/$(CONFIGNAME)/src` -Wl,-rpath,`abspath ../../Oversim-20121206/out/$(CONFIGNAME)/src`

# Output directory
PROJECT_OUTPUT_DIR = ../out
PROJECTRELATIVE_PATH = src
O = $(PROJECT_OUTPUT_DIR)/$(CONFIGNAME)/$(PROJECTRELATIVE_PATH)

# Object files for local .cc and .msg files
OBJS = $O/ZeroChurn.o $O/ManetChord.o $O/DummyUnderlayConfigurator.o

# Message files
MSGFILES =

# Other makefile variables (-K)
INETMANET_2_0_PROJ=../../inetmanet-2.0
OVERSIM_20121206_PROJ=../../Oversim-20121206

#------------------------------------------------------------------------------

# Pull in OMNeT++ configuration (Makefile.inc or configuser.vc)

ifneq ("$(OMNETPP_CONFIGFILE)","")
CONFIGFILE = $(OMNETPP_CONFIGFILE)
else
ifneq ("$(OMNETPP_ROOT)","")
CONFIGFILE = $(OMNETPP_ROOT)/Makefile.inc
else
CONFIGFILE = $(shell opp_configfilepath)
endif
endif

ifeq ("$(wildcard $(CONFIGFILE))","")
$(error Config file '$(CONFIGFILE)' does not exist -- add the OMNeT++ bin directory to the path so that opp_configfilepath can be found, or set the OMNETPP_CONFIGFILE variable to point to Makefile.inc)
endif

include $(CONFIGFILE)

# Simulation kernel and user interface libraries
OMNETPP_LIB_SUBDIR = $(OMNETPP_LIB_DIR)/$(TOOLCHAIN_NAME)
OMNETPP_LIBS = -L"$(OMNETPP_LIB_SUBDIR)" -L"$(OMNETPP_LIB_DIR)" -loppmain$D $(USERIF_LIBS) $(KERNEL_LIBS) $(SYS_LIBS)

COPTS = $(CFLAGS) -DINET_IMPORT $(INCLUDE_PATH) -I$(OMNETPP_INCL_DIR)
MSGCOPTS = $(INCLUDE_PATH)

# we want to recompile everything if COPTS changes,
# so we store COPTS into $COPTS_FILE and have object
# files depend on it (except when "make depend" was called)
COPTS_FILE = $O/.last-copts
ifneq ($(MAKECMDGOALS),depend)
ifneq ("$(COPTS)","$(shell cat $(COPTS_FILE) 2>/dev/null || echo '')")
$(shell $(MKPATH) "$O" && echo "$(COPTS)" >$(COPTS_FILE))
endif
endif

#------------------------------------------------------------------------------
# User-supplied makefile fragment(s)
# >>>
# <<<
#------------------------------------------------------------------------------

# Main target
all: $O/$(TARGET)
	$(Q)$(LN) $O/$(TARGET) .

$O/$(TARGET): $(OBJS)  $(wildcard $(EXTRA_OBJS)) Makefile
	@$(MKPATH) $O
	@echo Creating executable: $@
	$(Q)$(CXX) $(LDFLAGS) -o $O/$(TARGET)  $(OBJS) $(EXTRA_OBJS) $(AS_NEEDED_OFF) $(WHOLE_ARCHIVE_ON) $(LIBS) $(WHOLE_ARCHIVE_OFF) $(OMNETPP_LIBS)

.PHONY: all clean cleanall depend msgheaders

.SUFFIXES: .cc

$O/%.o: %.cc $(COPTS_FILE)
	@$(MKPATH) $(dir $@)
	$(qecho) "$<"
	$(Q)$(CXX) -c $(CXXFLAGS) $(COPTS) -o $@ $<

%_m.cc %_m.h: %.msg
	$(qecho) MSGC: $<
	$(Q)$(MSGC) -s _m.cc $(MSGCOPTS) $?

msgheaders: $(MSGFILES:.msg=_m.h)

clean:
	$(qecho) Cleaning...
	$(Q)-rm -rf $O
	$(Q)-rm -f p2psipmanet p2psipmanet.exe libp2psipmanet.so libp2psipmanet.a libp2psipmanet.dll libp2psipmanet.dylib
	$(Q)-rm -f ./*_m.cc ./*_m.h

cleanall: clean
	$(Q)-rm -rf $(PROJECT_OUTPUT_DIR)

depend:
	$(qecho) Creating dependencies...
	$(Q)$(MAKEDEPEND) $(INCLUDE_PATH) -f Makefile -P\$$O/ -- $(MSG_CC_FILES)  ./*.cc

# DO NOT DELETE THIS LINE -- make depend depends on it.
$O/DummyUnderlayConfigurator.o: DummyUnderlayConfigurator.cc \
	$(OVERSIM_20121206_PROJ)/src/common/BaseLocation.h \
	$(OVERSIM_20121206_PROJ)/src/common/BinaryValue.h \
	$(OVERSIM_20121206_PROJ)/src/common/ChurnGenerator.h \
	$(OVERSIM_20121206_PROJ)/src/common/GlobalNodeList.h \
	$(OVERSIM_20121206_PROJ)/src/common/GlobalNodeListAccess.h \
	$(OVERSIM_20121206_PROJ)/src/common/GlobalStatistics.h \
	$(OVERSIM_20121206_PROJ)/src/common/GlobalStatisticsAccess.h \
	$(OVERSIM_20121206_PROJ)/src/common/HashFunc.h \
	$(OVERSIM_20121206_PROJ)/src/common/InitStages.h \
	$(OVERSIM_20121206_PROJ)/src/common/NodeHandle.h \
	$(OVERSIM_20121206_PROJ)/src/common/OverlayKey.h \
	$(OVERSIM_20121206_PROJ)/src/common/PeerInfo.h \
	$(OVERSIM_20121206_PROJ)/src/common/PeerStorage.h \
	$(OVERSIM_20121206_PROJ)/src/common/StringConvert.h \
	$(OVERSIM_20121206_PROJ)/src/common/TransportAddress.h \
	$(OVERSIM_20121206_PROJ)/src/common/UnderlayConfigurator.h \
	$(OVERSIM_20121206_PROJ)/src/common/oversim_byteswap.h \
	$(OVERSIM_20121206_PROJ)/src/common/oversim_mapset.h \
	$(OVERSIM_20121206_PROJ)/src/underlay/simpleunderlay/SimpleInfo.h \
	$(OVERSIM_20121206_PROJ)/src/underlay/simpleunderlay/SimpleNodeEntry.h \
	$(OVERSIM_20121206_PROJ)/src/underlay/simpleunderlay/SimpleTCP.h \
	$(OVERSIM_20121206_PROJ)/src/underlay/simpleunderlay/SimpleUDP.h \
	$(INETMANET_2_0_PROJ)/src/base/BasicModule.h \
	$(INETMANET_2_0_PROJ)/src/base/ByteArray.h \
	$(INETMANET_2_0_PROJ)/src/base/ByteArray_m.h \
	$(INETMANET_2_0_PROJ)/src/base/Compat.h \
	$(INETMANET_2_0_PROJ)/src/base/ILifecycle.h \
	$(INETMANET_2_0_PROJ)/src/base/INETDefs.h \
	$(INETMANET_2_0_PROJ)/src/base/INotifiable.h \
	$(INETMANET_2_0_PROJ)/src/base/ModuleAccess.h \
	$(INETMANET_2_0_PROJ)/src/base/NotificationBoard.h \
	$(INETMANET_2_0_PROJ)/src/base/NotifierConsts.h \
	$(INETMANET_2_0_PROJ)/src/linklayer/contract/MACAddress.h \
	$(INETMANET_2_0_PROJ)/src/networklayer/common/IInterfaceTable.h \
	$(INETMANET_2_0_PROJ)/src/networklayer/common/InterfaceEntry.h \
	$(INETMANET_2_0_PROJ)/src/networklayer/common/InterfaceToken.h \
	$(INETMANET_2_0_PROJ)/src/networklayer/contract/IPv4Address.h \
	$(INETMANET_2_0_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INETMANET_2_0_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INETMANET_2_0_PROJ)/src/networklayer/contract/IPvXAddressResolver.h \
	$(INETMANET_2_0_PROJ)/src/networklayer/ipv4/IPv4InterfaceData.h \
	$(INETMANET_2_0_PROJ)/src/networklayer/ipv6/IPv6InterfaceData.h \
	$(INETMANET_2_0_PROJ)/src/transport/contract/TCPCommand_m.h \
	$(INETMANET_2_0_PROJ)/src/transport/contract/UDPControlInfo.h \
	$(INETMANET_2_0_PROJ)/src/transport/contract/UDPControlInfo_m.h \
	$(INETMANET_2_0_PROJ)/src/transport/tcp/TCP.h \
	$(INETMANET_2_0_PROJ)/src/transport/tcp/TCPConnection.h \
	$(INETMANET_2_0_PROJ)/src/transport/tcp_common/TCPSegment.h \
	$(INETMANET_2_0_PROJ)/src/transport/tcp_common/TCPSegment_m.h \
	$(INETMANET_2_0_PROJ)/src/transport/udp/UDP.h \
	$(INETMANET_2_0_PROJ)/src/transport/udp/UDPPacket_m.h \
	DummyUnderlayConfigurator.h
$O/ManetChord.o: ManetChord.cc \
	$(OVERSIM_20121206_PROJ)/src/common/AbstractLookup.h \
	$(OVERSIM_20121206_PROJ)/src/common/BaseApp.h \
	$(OVERSIM_20121206_PROJ)/src/common/BaseLocation.h \
	$(OVERSIM_20121206_PROJ)/src/common/BaseOverlay.h \
	$(OVERSIM_20121206_PROJ)/src/common/BaseRpc.h \
	$(OVERSIM_20121206_PROJ)/src/common/BaseTcpSupport.h \
	$(OVERSIM_20121206_PROJ)/src/common/BinaryValue.h \
	$(OVERSIM_20121206_PROJ)/src/common/BootstrapList.h \
	$(OVERSIM_20121206_PROJ)/src/common/BootstrapNodeHandle.h \
	$(OVERSIM_20121206_PROJ)/src/common/ChurnGenerator.h \
	$(OVERSIM_20121206_PROJ)/src/common/CommonMessages_m.h \
	$(OVERSIM_20121206_PROJ)/src/common/Comparator.h \
	$(OVERSIM_20121206_PROJ)/src/common/CoordinateSystem.h \
	$(OVERSIM_20121206_PROJ)/src/common/ExtTCPSocketMap.h \
	$(OVERSIM_20121206_PROJ)/src/common/GlobalNodeList.h \
	$(OVERSIM_20121206_PROJ)/src/common/GlobalParameters.h \
	$(OVERSIM_20121206_PROJ)/src/common/GlobalStatistics.h \
	$(OVERSIM_20121206_PROJ)/src/common/GlobalStatisticsAccess.h \
	$(OVERSIM_20121206_PROJ)/src/common/HashFunc.h \
	$(OVERSIM_20121206_PROJ)/src/common/InitStages.h \
	$(OVERSIM_20121206_PROJ)/src/common/IterativeLookupConfiguration.h \
	$(OVERSIM_20121206_PROJ)/src/common/NeighborCache.h \
	$(OVERSIM_20121206_PROJ)/src/common/NodeHandle.h \
	$(OVERSIM_20121206_PROJ)/src/common/NodeVector.h \
	$(OVERSIM_20121206_PROJ)/src/common/Nps.h \
	$(OVERSIM_20121206_PROJ)/src/common/Nps_m.h \
	$(OVERSIM_20121206_PROJ)/src/common/OverSimMessage.h \
	$(OVERSIM_20121206_PROJ)/src/common/OverSimMessage_m.h \
	$(OVERSIM_20121206_PROJ)/src/common/OverlayKey.h \
	$(OVERSIM_20121206_PROJ)/src/common/PeerInfo.h \
	$(OVERSIM_20121206_PROJ)/src/common/PeerStorage.h \
	$(OVERSIM_20121206_PROJ)/src/common/ProxNodeHandle.h \
	$(OVERSIM_20121206_PROJ)/src/common/RecursiveLookup.h \
	$(OVERSIM_20121206_PROJ)/src/common/RpcListener.h \
	$(OVERSIM_20121206_PROJ)/src/common/RpcMacros.h \
	$(OVERSIM_20121206_PROJ)/src/common/RpcState.h \
	$(OVERSIM_20121206_PROJ)/src/common/SVivaldi.h \
	$(OVERSIM_20121206_PROJ)/src/common/SimpleNcs.h \
	$(OVERSIM_20121206_PROJ)/src/common/SimpleUnderlayNCS.h \
	$(OVERSIM_20121206_PROJ)/src/common/TopologyVis.h \
	$(OVERSIM_20121206_PROJ)/src/common/TransportAddress.h \
	$(OVERSIM_20121206_PROJ)/src/common/TreeManagement.h \
	$(OVERSIM_20121206_PROJ)/src/common/TreeManagementMessage_m.h \
	$(OVERSIM_20121206_PROJ)/src/common/Vector2D.h \
	$(OVERSIM_20121206_PROJ)/src/common/Vivaldi.h \
	$(OVERSIM_20121206_PROJ)/src/common/cbr/CoordBasedRouting.h \
	$(OVERSIM_20121206_PROJ)/src/common/cbr/globalViewBuilder/AreaDataContainer.h \
	$(OVERSIM_20121206_PROJ)/src/common/cbr/globalViewBuilder/CoordDataContainer.h \
	$(OVERSIM_20121206_PROJ)/src/common/cbr/globalViewBuilder/RegionDataContainer.h \
	$(OVERSIM_20121206_PROJ)/src/common/cbr/globalViewBuilder/SimpleCoordDataContainer.h \
	$(OVERSIM_20121206_PROJ)/src/common/cbr/simplex.h \
	$(OVERSIM_20121206_PROJ)/src/common/cbr/yang.h \
	$(OVERSIM_20121206_PROJ)/src/common/oversim_byteswap.h \
	$(OVERSIM_20121206_PROJ)/src/common/oversim_mapset.h \
	$(OVERSIM_20121206_PROJ)/src/overlay/chord/Chord.h \
	$(OVERSIM_20121206_PROJ)/src/overlay/chord/ChordFingerTable.h \
	$(OVERSIM_20121206_PROJ)/src/overlay/chord/ChordMessage_m.h \
	$(OVERSIM_20121206_PROJ)/src/overlay/chord/ChordSuccessorList.h \
	$(OVERSIM_20121206_PROJ)/src/underlay/simpleunderlay/SimpleInfo.h \
	$(OVERSIM_20121206_PROJ)/src/underlay/simpleunderlay/SimpleNodeEntry.h \
	$(INETMANET_2_0_PROJ)/src/base/ByteArray.h \
	$(INETMANET_2_0_PROJ)/src/base/ByteArray_m.h \
	$(INETMANET_2_0_PROJ)/src/base/Compat.h \
	$(INETMANET_2_0_PROJ)/src/base/INETDefs.h \
	$(INETMANET_2_0_PROJ)/src/base/INotifiable.h \
	$(INETMANET_2_0_PROJ)/src/networklayer/contract/IPv4Address.h \
	$(INETMANET_2_0_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INETMANET_2_0_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INETMANET_2_0_PROJ)/src/transport/contract/TCPCommand_m.h \
	$(INETMANET_2_0_PROJ)/src/transport/contract/TCPSocket.h \
	$(INETMANET_2_0_PROJ)/src/transport/contract/TCPSocketMap.h \
	$(INETMANET_2_0_PROJ)/src/transport/contract/UDPSocket.h \
	$(INETMANET_2_0_PROJ)/src/transport/tcp_common/TCPSegment.h \
	$(INETMANET_2_0_PROJ)/src/transport/tcp_common/TCPSegment_m.h \
	$(INETMANET_2_0_PROJ)/src/transport/udp/UDPPacket_m.h \
	ManetChord.h
$O/ZeroChurn.o: ZeroChurn.cc \
	$(OVERSIM_20121206_PROJ)/src/common/ChurnGenerator.h \
	$(OVERSIM_20121206_PROJ)/src/common/InitStages.h \
	$(OVERSIM_20121206_PROJ)/src/common/TransportAddress.h \
	$(OVERSIM_20121206_PROJ)/src/common/UnderlayConfigurator.h \
	$(OVERSIM_20121206_PROJ)/src/common/UnderlayConfiguratorAccess.h \
	$(OVERSIM_20121206_PROJ)/src/common/oversim_mapset.h \
	$(INETMANET_2_0_PROJ)/src/base/Compat.h \
	$(INETMANET_2_0_PROJ)/src/base/INETDefs.h \
	$(INETMANET_2_0_PROJ)/src/networklayer/contract/IPv4Address.h \
	$(INETMANET_2_0_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INETMANET_2_0_PROJ)/src/networklayer/contract/IPvXAddress.h \
	ZeroChurn.h

