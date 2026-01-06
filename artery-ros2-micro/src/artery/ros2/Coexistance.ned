package artery.ros2;

import inet.networklayer.configurator.ipv4.IPv4NetworkConfigurator;
import inet.common.geometry.common.IGeographicCoordinateSystem;
import inet.environment.contract.IPhysicalEnvironment;
import inet.physicallayer.contract.packetlevel.IRadioMedium;
import inet.node.inet.AdhocHost;
import inet.physicallayer.common.packetlevel.RadioMedium;
import inet.visualizer.integrated.IntegratedCanvasVisualizer;
import ros2.Connector;

network Coexistance
{
    parameters:
        bool withPhysicalEnvironment = default(false);
        int numRoadSideUnits = default(0);

    submodules:
        visualizer: IntegratedCanvasVisualizer {
            @display("p=50,50");
        }
        ros2: Connector {
            parameters:
                @display("p=20,20");
                robotController.creationPolicy.moduleType = default("artery.ros2.Robot");
                robotController.creationPolicy.robotSinkPath = default(".mobility");
        }

        radioMedium: <default("Ieee80211ScalarRadioMedium")> like IRadioMedium {
            parameters:
                @display("p=60,20");
                mediumLimitCache.carrierFrequency = 5.9GHz;
        }

        physicalEnvironment: <default("PhysicalEnvironment")> like IPhysicalEnvironment if withPhysicalEnvironment {
            parameters:
                @display("p=100,20");
        }

        coordinateSystem: <default("SimpleGeographicCoordinateSystem")> like IGeographicCoordinateSystem {
            parameters:
                @display("p=140,20");
        }

        configurator: IPv4NetworkConfigurator {
            parameters:
                @display("p=200,20");
        }

        rsu[numRoadSideUnits]: RSU {
            parameters:
                mobility.initFromDisplayString = false;
        }

        wifiHost1: AdhocHost {
            @display("p=25,15;i=device/laptop");
        }

        wifiHost2: AdhocHost {
            @display("p=15,25;i=device/laptop");
        }
}
