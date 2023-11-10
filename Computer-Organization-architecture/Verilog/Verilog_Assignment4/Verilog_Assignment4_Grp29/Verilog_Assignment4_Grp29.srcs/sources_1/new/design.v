/*
    Header : 

    Assignment : Verilog Assignment 4
    Problem number : 1
    Group no. 29

    Bannuru Rohit Kumar Reddy - 21CS30011
    Dumpala Hashmitha - 21CS10023
*/

module Booth_Multiplication(clk, rst, start, A, M, valid, Z);

  // Defining the inputs : 

  input clk;             
  input rst;                
  input start;  

  // A,B are 8 bit signed inputs    

  input signed [7:0] A, M;  
  output signed [15:0] Z;   
  output valid;  


  // Declaring temporary variables :     

  reg [1:0] temp, next;             
  reg [2:0] count, nex_count; 
  reg signed [15:0] Z, next_Z, Z_temp;  
  reg next_state, present_state;           
  reg valid, nex_valid;                 

  parameter IDLE = 1'b0;  
  parameter START = 1'b1; 

  // Sequential logic: triggered on clock edge or reset
  always @(posedge clk or negedge rst) begin
    if (!rst) begin
      Z <= 16'd0;          // Reset Z to 0
      valid <= 1'b0;       // Reset valid signal
      present_state <= 1'b0;  // Reset present state to 0
      temp <= 2'd0;        // Reset temporary values
      count <= 3'd0;       // Reset count
    end else begin
      Z <= next_Z;          // Update Z with next value
      valid <= nex_valid;  // Update valid signal
      present_state <= next_state;  // Update present state
      temp <= next;          // Update temporary values
      count <= nex_count;        // Update count
    end
  end

  // Combinational logic: based on present state
  always @ (*) begin 
    case (present_state)
      IDLE:
        begin

          nex_count = 3'b0;           // Reset count
          nex_valid = 1'b0;           // Reset valid signal

          if (start) begin             // If start signal is asserted
            next_state = START;        // Move to START state
            next = {A[0], 1'b0};  // Initialize next with A[0] and 0
            next_Z = {8'd0, A};        // Initialize next_Z with A shifted left by 8 bits
          end else 

          begin               // If start signal is not asserted
            next_state = present_state;   // Stay in the IDLE state
            next = 2'd0;          // Reset next
            next_Z = 16'd0;            // Reset next_Z
          end
          
        end

      START:
        begin
          case (temp)

            2'b10: Z_temp = {Z[15:8] - M, Z[7:0]}; // Subtract M from upper 8 bits of Z
            2'b01: Z_temp = {Z[15:8] + M, Z[7:0]}; // Add M to upper 8 bits of Z

            default: Z_temp = {Z[15:8], Z[7:0]};    // Default: no operation on upper bits

          endcase

          next = {A[count+1], A[count]};  // Update next with A[count+1:count]
          nex_count = count + 1'b1;          // Increment count
          next_Z = Z_temp >>> 1;               // Right shift Z_temp to prepare for next iteration
          nex_valid = (&count) ? 1'b1 : 1'b0; // If count is not zero, set valid
          next_state = (&count) ? IDLE : present_state; // If count is not zero, go to IDLE

        end
    endcase
  end
endmodule
