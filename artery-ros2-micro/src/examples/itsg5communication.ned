package examples;

import inet.physicallayer.common.packetlevel.RadioMedium;
import inet.physicallayer.contract.packetlevel.IRadioMedium;
import inet.visualizer.integrated.IntegratedCanvasVisualizer;
import inet.environment.contract.IPhysicalEnvironment;
import artery.application.InfrastructureMockService;
import artery.application.InfrastructureMockReceiver;

network itsg5communication
{
    @display("bgb=539,382");
    submodules:
        visualizer: IntegratedCanvasVisualizer {
            @display("p=61,103");
        }

        radioMedium: <default("Ieee80211ScalarRadioMedium")> like IRadioMedium {
            parameters:
                @display("p=60,20");
                mediumLimitCache.carrierFrequency = 5.9GHz;
        }

        physicalEnvironment: <default("PhysicalEnvironment")> like IPhysicalEnvironment {
            parameters:
                @display("p=155,20");
        }

        rsu_sender: InfrastructureMockService {
            parameters:
                @display("p=442,50");
        }

        rsu_receiver: InfrastructureMockReceiver {
            parameters:
                @display("p=442,224");
        }

}
