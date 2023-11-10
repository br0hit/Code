`timescale 1ns/1ps

module testbench;

    // Inputs
  reg [2:0] source,destination;
    reg  move,in,clk;
  reg [15:0] data_in

    // Outputs
  wire [15:0] src_data;

  // Instantiate the toplevel module
  toplevel dut (
      .source(source),
      .destination(destination),
      .move(move),
      .in(in),
      .clk(clk),
      .data_in(data_in),
      .src_data(src_data)
  );

    // Clock generation
    reg clk = 0;
    always #5 clk = ~clk;
  
  initial begin
    $monitor("Input wire :%d Register Number:%d Load bit:%d Enable bit:%d Output Register:%d", inputNumber, registerNumber, load, enable, clk, outputData );
    
    #100
    
        source = 1;
        desitnation = 3;
        move = 0;
        in = 1;
    	data_in = 15;
    
	
    #100
    
        source = 1;
        desitnation = 3;
        move = 1;
        in = 0;
    	data_in = 15;
	
    #100
    
        source = 1;
        desitnation = 3;
        move = 1;
        in = 0;
    	data_in = 15;
	
    #100
    
        source = 1;
        desitnation = 3;
        move = 1;
        in = 0;
    	data_in = 15;
    
      #100
            
        #100; 
        $finish;
    end

endmodule


