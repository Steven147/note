module D0_display( //注释参考实验一
    input [3:0] D0_bits ,
    input [3:0] D0_NUM ,
    output reg [6:0] D0_a_to_g ,
    output [3:0] D0_led_bits
    );
    
    assign D0_led_bits = D0_bits ;
    
    always @(*)
    begin
        case(D0_NUM)
        0:D0_a_to_g=7'b1111110;
        1:D0_a_to_g=7'b0110000;
        //2:D0_a_to_g=7'b1101101;
        //3:D0_a_to_g=7'b1111001;   
        //4:D0_a_to_g=7'b0110011;
        //5:D0_a_to_g=7'b1011011;
        //6:D0_a_to_g=7'b1011111;
        //7:D0_a_to_g=7'b1110000;
        //8:D0_a_to_g=7'b1111111;
        //9:D0_a_to_g=7'b1111011;
        //'hA: D0_a_to_g=7'b1110111;
        //'hB: D0_a_to_g=7'b0011111;
        //'hC: D0_a_to_g=7'b1001110;
        //'hD: D0_a_to_g=7'b0111101;
        'hE: D0_a_to_g=7'b1001111;
        //'hF: D0_a_to_g=7'b1000111;
        default: D0_a_to_g=7'b0000000;
        endcase
    end
endmodule

module Count_FFFF( //注释参考实验二
    input clk,
    input clr,
     
    input one, 
    input zero,
    input add,
    input sub, 
    input count,
     
    output [6:0] a_to_g ,
    output [3:0] led_bits
    );
    reg [3:0] num ;//储存单个数码管上需要显示的数字
    reg [35:0] ckl_cnt; 
    reg [3:0] t_led_bits ; //中间变量，存储数码管复用切换位控信息
    reg [3:0] number1 = 0;//储存输入的数字
    reg [3:0] number2 = 0;//储存输入的数字
    reg [3:0] value = 0; 
    reg [1:0] state = 1;
    reg func = 0;
    reg flag = 1;
 
    always@(posedge clk)
    begin
        ckl_cnt = ckl_cnt + 1 ;
        
        if(state)//在检测到一和零的输入时记录数字
        begin
            if(one)
            begin
                if(flag)
                begin
                    number1[3] = number1[2];
                    number1[2] = number1[1];
                    number1[1] = number1[0];
                    number1[0] = 1;
                    value = number1;
                    flag = 0;
                end
            end
            else if(zero) 
            begin 
                if(flag)
                begin
                    number1[3] = number1[2]; 
                    number1[2] = number1[1];
                    number1[1] = number1[0];
                    number1[0] = 0;
                    value = number1;
                    flag = 0;
                 end
            end
            else flag = 1;
        end
        else//检测为零 记录在末尾
        begin
            if(one)
            begin
                if(flag)
                begin
                    number2[3] = number2[2];
                    number2[2] = number2[1];
                    number2[1] = number2[0];
                    number2[0] = 1;
                    value = number2;
                    flag = 0;
                end
            end
            else if(zero) 
            begin 
                if(flag)
                begin
                    number2[3] = number2[2]; 
                    number2[2] = number2[1];
                    number2[1] = number2[0];
                    number2[0] = 0;
                    value = number2;
                    flag = 0;
                 end
            end
            else flag = 1;
        end      
        
        if(add)
        begin 
            state = 0;
            func = 1;
        end
        else if(sub)
        begin
            state = 0;
            func = 0;
        end
        
        else if(count)
        begin
            if (func) value = number1 + number2;
            else value = number1 - number2;
        end
        else if(clr)
        begin
            if (func) value = number1 + number2;
            else value = number1 - number2;
            state = 1;
            value = 0;
            number1 = 0;
            number2 = 0;
        end
    end
 
    always@(*) //取计数变量的高 16 位组成要显示的 1 个 4 位十六进制数
        case(ckl_cnt[15:14]) //取计数变量的较低 2 位(频率高)数值，作为 4 位数码管扫描复位切换频率
        0:begin num <= value[0]; t_led_bits <= 4'b0001;end //数码管 1 有效，
        1:begin num <= value[1];t_led_bits <= 4'b0010;end //数码管 2 有效，
        2:begin num <= value[2];t_led_bits <= 4'b0100;end //数码管 3 有效，
        3:begin num <= value[3];t_led_bits <= 4'b1000;end //数码管 4 有效，
        endcase
  
    D0_display myD0_display(.D0_bits(t_led_bits),.D0_NUM(num),.D0_a_to_g(a_to_g),.D0_led_bits(led_bits)) ;
endmodule