package artery.ros2;

import inet.mobility.contract.IMobility;

simple ArrowheadRobotInetMobility like IMobility
{
    parameters:
        @signal[mobilityStateChanged];
        @signal[robotPositionChanged](type=ros2::RobotObject);
        @signal[localizationPositionChanged](type=ros2::RobotObject);
        @signal[simulationPositionChanged](type=ros2::RobotObject);
        @signal[serviceRegistryUpdated](type=ros2::ServiceObject);
        string visualRepresentation = default("");
        string coordinateSystemModule = default("coordinateSystem");
}
