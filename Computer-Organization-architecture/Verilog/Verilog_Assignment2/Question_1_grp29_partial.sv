`timescale 1ns/1ps

module RegisterBank (
    input wire [15:0] inputNumber,
    input wire [2:0] registerNumber,
    input wire load,
    input wire enable,
    output wire [15:0] outputData
);

    reg [15:0] R0, R1, R2, R3, R4, R5, R6, R7;
    reg [15:0] selectedRegisterData;

    // Parallel load functionality
    always @(posedge load) begin
        case (registerNumber)
            3'b000: R0 <= inputNumber;
            3'b001: R1 <= inputNumber;
            3'b010: R2 <= inputNumber;
            3'b011: R3 <= inputNumber;
            3'b100: R4 <= inputNumber;
            3'b101: R5 <= inputNumber;
            3'b110: R6 <= inputNumber;
            3'b111: R7 <= inputNumber;
        endcase
    end

    // Output selection logic
    always @(posedge enable) begin
        case (registerNumber)
            3'b000: selectedRegisterData <= R0;
            3'b001: selectedRegisterData <= R1;
            3'b010: selectedRegisterData <= R2;
            3'b011: selectedRegisterData <= R3;
            3'b100: selectedRegisterData <= R4;
            3'b101: selectedRegisterData <= R5;
            3'b110: selectedRegisterData <= R6;
            3'b111: selectedRegisterData <= R7;
            default: selectedRegisterData <= 16'b0; // High-impedance state
        endcase
    end

    assign outputData = enable ? selectedRegisterData : 16'bz; // High-impedance state when not enabled

endmodule
