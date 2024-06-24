class MiniHashHumanoid
{
  public:

    /* Variable declaration */
    int servo_position[16];
    float increment[16];
    unsigned long final_time;
    unsigned long partial_time;

    /* Method declaration */
    void init_hash();
    void set_servo(int servo, int servo_pwm);
    void initial_position();
    void move_servo(int time, int servo_target[]);
    
    void say_hi(int count = 1);
    void hands_up();
    void hands_down();
    void hand_wave(int count = 1);
    void right_leg_wave(int count = 2);
    void left_leg_wave(int count = 2);
    void leg_hand_shake(int count = 3);
    void right_slide_wave(int count = 2);
    void left_slide_wave(int count = 2);
    void flying_hand_wave(int count = 1);
    void jump(int count = 1, int height = 30);
    void leg_head_shake(int count = 1);
    void flying(int count = 1);
    void leg_shake(int count = 1);
    void hand_straight_shake(int count = 3);

    void move_forward(int steps = 1, int speed = 1000);
    void move_backward(int steps = 1, int speed = 1000);
    void side_move_right(int steps = 1);
    void side_move_left(int steps = 1);
    void turn_left(int steps = 1, int speed = 1000);
    void turn_right(int steps = 1, int speed = 1000);
};

