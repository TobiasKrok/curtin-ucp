#include "input.h"
#include "macros.h"

int main(int argc, char* argv) {
    OperationResult validation_res = validate_args(argc, argv);

    if(validation_res.is_error == TRUE) {
        
    } 
}