package artery.ros2;

import artery.networking.IPositionProvider;

module ArrowheadRobotPositionProvider like IPositionProvider
{
    parameters:
        @class(ArrowheadRobotPositionProvider);
        @signal[PositionFix](PositionFixObject);
        @signal[robotPositionChanged](type=ros2::RobotObject);
        @signal[simulationPositionChanged](type=ros2::RobotObject);
        string runtimeModule;
        string mobilityModule;
}
