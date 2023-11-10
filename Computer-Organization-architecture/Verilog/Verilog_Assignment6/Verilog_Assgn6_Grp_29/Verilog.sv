// Verilog Assignment 6 - Memory Implementation 
// Group 29
// Name : Bannuru Rohit Kumar Reddy
// Name : Hashmitha Dumpala


// Defining the timescale : 
`timescale 1ns / 1ps

// Main Module : 

module MemorySystem ( func, reg_num, data_in, clk, address );

    // Declaring the variables as input : 

    input clk;
    input [1:0] func;         // Code declaring which operation should be performed 
    input[2:0] reg_num;       // Register number for which the opereation has to be performed 
    input wire[3:0] data_in ,address;           // Input data and the address ( Address is the location in the RAM memory )


    // Defining temporary variables :

    // Declaring a register bank in which there are 8 registers each of which can store a 3 bit integer  

    reg[3:0] regbank[0:7]; 

    reg[3:0] inp;             // Input data given to the memory 
    wire [3:0] data_out;      // Output data obtained form the memory  
    reg ena,wea;

    // ******* Declare the memory instance here *******
 
   blk_mem_gen_0 your_instance_name (
  .clka(clk),    
  .ena(ena),      
  .wea(wea),      
  .addra(address),  
  .dina(inp),   
  .douta(data_out)  
);


always @(posedge clk) begin 
    case(func)

      // Case 1 : Read a 4-bit data and store it into a specified memory location with 4-bit address

      2'b00:
      begin
            ena=1;
            wea=1;

            // Giving the input to the memory as the value given as input 
            inp=data_in;
      end

      // Case 2 : Given a register number and a memory address, transfer data from register to memory.

      2'b01:
      begin
            ena=1;
            wea=1;

            // Giving the input to the memory as the value stored in the register number 
            inp=regbank[reg_num];
      end

      // Case 3 : transfer data from memory to register

      2'b10:
      begin
            ena=1;
            wea=0;

            // After a time delay, Take the data_out from the memory and store it in the register bank 
            #5
            regbank[reg_num]=data_out;
      end

      // Case 4 : Given a memory address, display the contents of the memory location.

      2'b11:
      begin
            ena=1;
            wea=0;

            // Displaying the contents of the memory location 
            #15
            $display($time," dout is %d",data_out);
            end
      
      endcase
end
endmodule




