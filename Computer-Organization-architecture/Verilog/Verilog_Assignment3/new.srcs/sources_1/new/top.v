`timescale 1ns/1ps

// • result = in1 + in2
// Module: 8-Bit Carry Look-Ahead Adder using 2 4-Bit Adders in Structural Design

module ALU_0(a, b, cin, sum, cout);

  // Inputs:
  input [7:0] a, b; // 8-bit operands
  input cin;        // Carry-in

  // Outputs:
  output [7:0] sum; // 8-bit sum
  output cout;      // Carry-out

  // Temporary variable to store the intermediate carry of the first 4 bits:
  wire c1;

  // Instantiating two 4-bit adders to implement the 8-bit addition:
  Carry_Adder_4Bit cla1 (.a(a[3:0]), .b(b[3:0]), .cin(cin), .sum(sum[3:0]), .cout(c1));
  Carry_Adder_4Bit cla2 (.a(a[7:4]), .b(b[7:4]), .cin(c1), .sum(sum[7:4]), .cout(cout));

endmodule

// Module: 4-Bit Carry Look-Ahead Adder

module Carry_Adder_4Bit(a, b, cin, sum, cout);

  // Inputs:
  input [3:0] a, b; // 4-bit operands
  input cin;        // Carry-in
  
  // Outputs:
  output [3:0] sum; // 4-bit sum
  output cout;      // Carry-out

  // Intermediate wires for generating propagate (p), generate (g), and carry (c):
  wire [3:0] p, g, c;

  // Generating propagate and generate signals:
  assign p = a ^ b; // Propagate
  assign g = a & b; // Generate

  // Using a carry look-ahead method for the first 4 bits addition:

  // Calculate the carries using generate and propagate signals:
  assign c[0] = cin;
  assign c[1] = g[0] | (p[0] & c[0]);
  assign c[2] = g[1] | (p[1] & g[0]) | (p[1] & p[0] & c[0]);
  assign c[3] = g[2] | (p[2] & g[1]) | (p[2] & p[1] & g[0]) | (p[2] & p[1] & p[0] & c[0]);

  // Calculate the carry-out signal using the final carry bit (c[3]) and generate signals:
  assign cout = g[3] | (p[3] & g[2]) | (p[3] & p[2] & g[1]) | (p[3] & p[2] & p[1] & g[0]) | (p[3] & p[2] & p[1] & p[0] & c[0]);

  // Calculate the sum bits using the XOR of propagate and carry signals:
  assign sum = p ^ c;

endmodule

// • result = in1 ? in2

// Utility module for doing subraction : 

// Two's Complementer module
module TwosComplementer(input [7:0] num, output [7:0] twos_comp);
    wire [7:0] inverted = ~num;
    wire [7:0] one = 8'b00000001;
    wire [7:0] added = inverted + one;
    assign twos_comp = added;
endmodule


// Subtractor module using Two's Complement and Adder
module ALU_1(a, b, diff);
    input [7:0] a, b;
    output [7:0] diff;

    wire [7:0] neg_b;
    TwosComplementer comp(.num(b), .twos_comp(neg_b));

    wire [7:0] sum;
    wire cout;
    ALU_0 adder(.a(a), .b(neg_b), .cin(1'b1), .sum(sum), .cout(cout));

    assign diff = sum-1;
endmodule


// • result = in1

module ALU_2 (in1, clk, outp);

  input [7:0] in1;
  input clk;
  output reg [7:0] outp;
  
  always @(posedge clk) begin
  outp <= in1;
  
  end
endmodule

// • result = in1 << 1

module ALU_3 (in1, clk, outp);
  
  input [7:0] in1;
  input clk;
  output reg [7:0] outp;
  
  always @(posedge clk) begin
  outp <= in1<<1;
  
  end  
endmodule

// • result = in1 >> 1

module ALU_4 (in1, clk, outp);
  
  input [7:0] in1;
  input clk;
  output reg [7:0] outp;
  
  always @(posedge clk) begin
  outp <= in1>>1;
  
  end
endmodule

//• result = in1 AND in2

module ALU_5 (in1, in2, clk, outp);
  
  input [7:0] in1, in2;
  input clk;
  output reg [7:0] outp;
  
  always @(posedge clk) begin
  outp <= in1 & in2;
  
  end 
endmodule

// • result = NOT in1

module ALU_6 (in1, clk, outp);
  
  input [7:0] in1;
  input clk;
  output reg [7:0] outp;
  
  always @(posedge clk) begin
  outp <= ~in1;
  
  end
endmodule

//  • result = in1 OR in2

module ALU_7 (in1, in2, clk, outp);
  
  input [7:0] in1, in2;
  input clk;
  output reg [7:0] outp;
  
  always @(posedge clk) begin
  outp <= in1 | in2;
 
  end
endmodule
  
  
// The Top module : 
  
module Top (in1, in2, func, clk, result);
  
  // Declaring the input output 
  
  input [7:0] in1, in2;
  input [2:0] func;
  input clk;
  output [7:0] result;
  
  // Output and temp declared as reg :
  // Note: For each Submodule we define a temp so that depending upon the func value, we can load it into the result register 
  
  reg [7:0] result;
  wire [7:0] temp0,temp1,temp2,temp3,temp4,temp5,temp6,temp7;
  wire cout;
  
  // Initializing the submodules with the corresponding temp output  : 
  
  ALU_0 test0(in1, in2, 0, temp0, cout);
  ALU_1 test1(in1, in2, temp1);
  ALU_2 test2(in1, clk, temp2);
  ALU_3 test3(in1, clk, temp3);
  ALU_4 test4(in1, clk, temp4);
  ALU_5 test5(in1, in2, clk, temp5);
  ALU_6 test6(in1, clk, temp6);
  ALU_7 test7(in1, in2, clk, temp7);

  // Testing the submodules : 
	
    always @(posedge clk)
      begin
        case (func)
        
          3'b000: result <= temp0;
          3'b001: result <= temp1;
          3'b010: result <= temp2;  
          3'b011: result <= temp3;
          3'b100: result <= temp4;
          3'b101: result <= temp5;
          3'b110: result <= temp6;
          3'b111: result <= temp7;

          default: result <= 0;
          
        endcase
      end
  
endmodule



  
  