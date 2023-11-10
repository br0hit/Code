
// Verilog Assignment 6 - Memory Implementation 
// Group 29
// Name : Bannuru Rohit Kumar Reddy
// Name : Hashmitha Dumpala


// Defining the timescale : 
`timescale 1ns / 1ps

module tb();

  // Declaring the inputs to the MemorySystem Module as reg 
    reg clk=1;
    reg[1:0] func;
    reg [3:0] data_in,address; 
    reg[2:0] reg_num;

    // Defining the inputs to the top module : 

    MemorySystem test (
      .func(func),
      .reg_num(reg_num), 
      .clk(clk),  
      .address(address),  
      .data_in(data_in)   
      );

// Defining the time module : 
always #5 clk=~clk;

    initial 
        begin

          #10
            data_in=4;
            address=1;
            func=0;
          $display("Testing operation 1: Input data:%d Address:%d",data_in,address);

          #25
            func=3; 
          $display("Testing operation 4:Address:%d",address);

          #25
            reg_num=1;
            func=2;
          $display("Testing operation 3: Register Number:%d",reg_num);
          
          #25
            reg_num=1;
            address=5;
            func=1;
          $display("Testing operation 2: Register Number:%d Address:%d",reg_num,address);

          #25
            address=5;
            func=3;
          $display("Testing operation 4:Address:%d",address);

          #35
             $finish;    

    
  end      
  endmodule