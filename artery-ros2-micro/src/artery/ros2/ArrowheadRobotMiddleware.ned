package artery.ros2;

import artery.application.Middleware;

simple ArrowheadRobotMiddleware extends Middleware
{
    parameters:
        @class(ArrowheadRobotMiddleware);
        @signal[IdentityChanged](type=long);

        string localEnvironmentModule = default("");
        string globalEnvironmentModule = default("");
        string mobilityModule;
}

