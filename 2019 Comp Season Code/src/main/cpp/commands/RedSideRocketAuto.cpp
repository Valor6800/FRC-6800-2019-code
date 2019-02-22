#include "commands/RedSideRocketAuto.h"
#include "Robot.h"

RedSideRocketAuto::RedSideRocketAuto() {
    
    int POINT_LENGTH = 3;

    Waypoint points[POINT_LENGTH];

    Waypoint p1 = { 1.5, 3.0, d2r(0) };      // Waypoint @ x=-4, y=-1, exit angle=45 degrees
    Waypoint p2 = { 3.0, 3.0, d2r(0) };             // Waypoint @ x=-1, y= 2, exit angle= 0 radians
    Waypoint p3 = { 5.0, 0.7, d2r(79) };             // Waypoint @ x= 2, y= 4, exit angle= 0 radians
    points[0] = p1;
    points[1] = p2;
    points[2] = p3;

    TrajectoryCandidate candidate;

    // Prepare the Trajectory for Generation.
    //
    // Arguments: 
    // Fit Function:        FIT_HERMITE_CUBIC or FIT_HERMITE_QUINTIC
    // Sample Count:        PATHFINDER_SAMPLES_HIGH (100 000)
    //                      PATHFINDER_SAMPLES_LOW  (10 000)
    //                      PATHFINDER_SAMPLES_FAST (1 000)
    // Time Step:           0.001 Seconds
    // Max Velocity:        15 m/s
    // Max Acceleration:    10 m/s/s
    // Max Jerk:            60 m/s/s/s
    pathfinder_prepare(points, POINT_LENGTH, FIT_HERMITE_CUBIC, PATHFINDER_SAMPLES_HIGH, 0.02, 10.0, 2, 60, &candidate);

    int length = candidate.length;

    // Array of Segments (the trajectory points) to store the trajectory in
    Segment* trajectory =  (Segment*) malloc(sizeof(Segment) * length);    

    // Generate the trajectory
    pathfinder_generate(&candidate, trajectory);

    Segment leftTrajectory[length];
    Segment rightTrajectory[length];

    // The distance between the left and right sides of the wheelbase is 0.8m
    double wheelbase_width = 0.756;

    // Generate the Left and Right trajectories of the wheelbase using the 
    // originally generated trajectory
    pathfinder_modify_tank(trajectory, length, leftTrajectory, rightTrajectory, wheelbase_width);

    EncoderFollower* leftFollower = (EncoderFollower*) malloc(sizeof(EncoderFollower));
    leftFollower->last_error = 0; 
    leftFollower->segment = 0; 
    leftFollower->finished = 0;



    EncoderFollower* rightFollower = (EncoderFollower*) malloc(sizeof(EncoderFollower));
    rightFollower->last_error = 0; 
    rightFollower->segment = 0; 
    rightFollower->finished = 0;

    EncoderConfig leftConfig = { Robot::m_drivetrain.GetLeftEncoder(), 1000, .1524,      // Position, Ticks per Rev, Wheel Circumference
                         1.0, 0.0, 0.0, 1.0 / 10.0, 0.0};
    EncoderConfig rightConfig = { Robot::m_drivetrain.GetRightEncoder(), 1000, .1524,      // Position, Ticks per Rev, Wheel Circumference
                         1.0, 0.0, 0.0, 1.0 / 10.0, 0.0};

    // Arg 1: The EncoderConfig
    // Arg 2: The EncoderFollower for this side
    // Arg 3: The Trajectory generated from `pathfinder_modify_tank`
    // Arg 4: The Length of the Trajectory (length used in Segment seg[length];)
    // Arg 5: The current value of your encoder
    double l = pathfinder_follow_encoder(leftConfig, leftFollower, leftTrajectory, length, Robot::m_drivetrain.GetLeftEncoder());
    double r = pathfinder_follow_encoder(rightConfig, rightFollower, rightTrajectory, length, Robot::m_drivetrain.GetRightEncoder());

    // -- using l and r from the previous code block -- //
    double gyro_heading = ... your gyro code here ...      // Assuming gyro angle is given in degrees
    double desired_heading = r2d(leftFollower.heading);

    double angle_difference = desired_heading - gyro_heading;    // Make sure to bound this from -180 to 180, otherwise you will get super large values

    double turn = 0.8 * (-1.0/80.0) * angle_difference;

    setLeftMotors(l + turn);
    setRightMotors(r - turn);
    
}