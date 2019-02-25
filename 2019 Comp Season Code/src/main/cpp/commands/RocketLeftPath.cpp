#include "commands/RocketLeftPath.h"
#include "Robot.h"
#include <cmath>

RocketLeftPath::RocketLeftPath() {
    Requires(&Robot::m_drivetrain);
}

void RocketLeftPath::Initialize() {

    // // TrajectoryConfig left_trajectory = PathfinderFRC::get_trajectory(k_path_name + ".left");
    // // Trajectory right_trajectory = PathfinderFRC.getTrajectory(k_path_name + ".right");

    // // leftFollower = new EncoderFollower(left_trajectory);
    // // rightFollower = new EncoderFollower(right_trajectory);

    // // m_left_follower.configureEncoder(m_left_encoder.get(), k_ticks_per_rev, k_wheel_diameter);
    // // // You must tune the PID values on the following line!
    // // m_left_follower.configurePIDVA(1.0, 0.0, 0.0, 1 / k_max_velocity, 0);

    // // m_right_follower.configureEncoder(m_right_encoder.get(), k_ticks_per_rev, k_wheel_diameter);
    // // // You must tune the PID values on the following line!
    // // m_right_follower.configurePIDVA(1.0, 0.0, 0.0, 1 / k_max_velocity, 0);

    // const int POINT_LENGTH = 2;

    // Waypoint *points = (Waypoint*)malloc(sizeof(Waypoint) * POINT_LENGTH);

    // Waypoint p1 = { 0, 0, d2r(0) };      // Waypoint @ x=-4, y=-1, exit angle=45 degrees
    // Waypoint p2 = { 5.0, 0, d2r(0) };             // Waypoint @ x=-1, y= 2, exit angle= 0 radians
    // // Waypoint p3 = { 5.0, 0.7, d2r(79) };             // Waypoint @ x= 2, y= 4, exit angle= 0 radians
    // points[0] = p1;
    // points[1] = p2;
    // // points[2] = p3;

    // // Prepare the Trajectory for Generation.
    // //
    // // Arguments: 
    // // Fit Function:        FIT_HERMITE_CUBIC or FIT_HERMITE_QUINTIC
    // // Sample Count:        PATHFINDER_SAMPLES_HIGH (100 000)
    // //                      PATHFINDER_SAMPLES_LOW  (10 000)
    // //                      PATHFINDER_SAMPLES_FAST (1 000)
    // // Time Step:           0.001 Seconds
    // // Max Velocity:        15 m/s
    // // Max Acceleration:    10 m/s/s
    // // Max Jerk:            60 m/s/s/s
    // pathfinder_prepare(points, POINT_LENGTH, FIT_HERMITE_CUBIC, PATHFINDER_SAMPLES_HIGH, 0.02, 10.0, 2, 60, &candidate);
    // free(points);

    // const int length = candidate.length;

    // // Array of Segments (the trajectory points) to store the trajectory in
    // Segment* trajectory =  (Segment*)malloc(sizeof(Segment) * length);   

    // // Generate the trajectory
    // pathfinder_generate(&candidate, trajectory);

    // leftTrajectory = (Segment*)malloc(sizeof(Segment) * length);
    // rightTrajectory = (Segment*)malloc(sizeof(Segment) * length);

    // // The distance between the left and right sides of the wheelbase is 0.8m
    // double wheelbase_width = 0.756;

    // // Generate the Left and Right trajectories of the wheelbase using the 
    // // originally generated trajectory
    // pathfinder_modify_tank(trajectory, length, leftTrajectory, rightTrajectory, wheelbase_width);

    // leftFollower = (EncoderFollower*) malloc(sizeof(EncoderFollower));
    // leftFollower->last_error = 0; 
    // leftFollower->segment = 0; 
    // leftFollower->finished = 0;
    
    // rightFollower = (EncoderFollower*) malloc(sizeof(EncoderFollower));
    // rightFollower->last_error = 0; 
    // rightFollower->segment = 0; 
    // rightFollower->finished = 0;

    // leftConfig = { (int)Robot::m_drivetrain.GetLeftEncoder(), 18, .478,      // Position, Ticks per Rev, Wheel Circumference
    //                      .8, 0.0, 0.0, 1.0 / 10.0, 0.0};
    // rightConfig = { (int)Robot::m_drivetrain.GetRightEncoder(), 18, .478,      // Position, Ticks per Rev, Wheel Circumference
    //                      .8, 0.0, 0.0, 1.0 / 10.0, 0.0};

    // free(trajectory);

    length = PathfinderFRC::get_trajectory(k_path_name + ".right", leftTrajectory);
    PathfinderFRC::get_trajectory(k_path_name + ".left", rightTrajectory);

    leftFollower = (EncoderFollower*)malloc(sizeof(EncoderFollower));
    rightFollower = (EncoderFollower*)malloc(sizeof(EncoderFollower));

    leftConfig = { (int)Robot::m_drivetrain.GetLeftEncoder(), 18, .478,      // Position, Ticks per Rev, Wheel Circumference
                         .8, 0.0, 0.0, 1.0 / 10.0, 0.0};
    rightConfig = { (int)Robot::m_drivetrain.GetRightEncoder(), 18, .478,      // Position, Ticks per Rev, Wheel Circumference
                         .8, 0.0, 0.0, 1.0 / 10.0, 0.0};

}

void RocketLeftPath::Execute() {
    // Arg 1: The EncoderConfig
    // Arg 2: The EncoderFollower for this side
    // Arg 3: The Trajectory generated from `pathfinder_modify_tank`
    // Arg 4: The Length of the Trajectory (length used in Segment seg[length];)
    // Arg 5: The current value of your encoder
    l = pathfinder_follow_encoder(leftConfig, leftFollower, leftTrajectory, length, Robot::m_drivetrain.GetLeftEncoder());
    r = pathfinder_follow_encoder(rightConfig, rightFollower, rightTrajectory, length, Robot::m_drivetrain.GetRightEncoder());

    // -- using l and r from the previous code block -- //
    gyro_heading = Robot::m_drivetrain.GetHeading();   // Assuming gyro angle is given in degrees
    desired_heading = -r2d(leftFollower->heading);

    angle_difference = desired_heading - gyro_heading;    // Make sure to bound this from -180 to 180, otherwise you will get super large values

    turn = .8 * (-1.0/80.0) * angle_difference;

    Robot::m_drivetrain.TankDrive(l + turn, r - turn);
}

bool RocketLeftPath::IsFinished() {

    return leftFollower->finished || rightFollower->finished;
}

void RocketLeftPath::End() {
    Robot::m_drivetrain.TankDrive(0, 0);
    free(leftTrajectory);
    free(rightTrajectory);
    free(leftFollower);
    free(rightFollower);
}
    
//     
// }