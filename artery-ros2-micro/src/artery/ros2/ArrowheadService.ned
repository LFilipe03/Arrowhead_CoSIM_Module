package artery.ros2;

import artery.application.ItsG5Service;

simple ArrowheadService like ItsG5Service
{
    @signal[ArrowheadMsgReceived](type=ros2::ServiceObject);
    string coordinateSystemModule = default("coordinateSystem");
}