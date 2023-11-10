module substractor(y0, x0, bin, bout, diff);
  input [7:0] x0;       // 8-bit input representing the dividend
  input [7:0] y0;       // 8-bit input representing the remainder
  output [7:0] diff;    // 8-bit output representing the quotient
  input bin;            // Binary control signal
  output bout;          // Output signal indicating the end of division
 
  wire [7:0] temp;      // Wire to hold the intermediate result
 
  // Calculate the temporary result by adding 'bin' to 'x0'
  assign temp = x0 + bin;
 
  // Calculate 'diff' by subtracting 'temp' from 'y0' and assign it along with 'bout'
  assign {bout, diff} = y0 - temp;
endmodule

// Module top_level: Top-level module that instantiates four instances of the 'substractor' module
// to perform division by 255 on a 32-bit input 'x'. The result 'y' is a 32-bit quotient.

module top_level(x, clk, y);
  input [31:0] x;       // 32-bit input representing the dividend
  input clk;            // Clock signal
  output [31:0] y;      // 32-bit output representing the quotient
 
  reg [7:0] x4, x3, x2, x1;  // Registers to hold the 8-bit portions of 'x'
  wire [7:0] y4, y3, y2, y1; // Wires to hold the 8-bit portions of the quotient
  wire b4, b3, b2, b1;       // Wires to indicate division completion for each stage
 
  // Instantiate four instances of the 'substractor' module to perform division by 255
 
  substractor sub1(.y0(8'b00000000), .x0(x1), .bin(1'b0), .bout(b1), .diff(y1));
  substractor sub2(.y0(y1), .x0(x2), .bin(b1), .bout(b2), .diff(y2));
  substractor sub3(.y0(y2), .x0(x3), .bin(b2), .bout(b3), .diff(y3));
  substractor sub4(.y0(y3), .x0(x4), .bin(b3), .bout(b4), .diff(y4));
 
  // Clocked process to update 'x1', 'x2', 'x3', 'x4' with the portions of 'x'
  always @(posedge clk)
  begin
    x1 <= x[7:0];
    x2 <= x[15:8];
    x3 <= x[23:16];
    x4 <= x[31:24];
  end
 
  // Concatenate the 8-bit quotient portions to form the 32-bit quotient 'y'
  assign y = {y4, y3, y2, y1};
 
endmodule




