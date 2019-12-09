# auralizer

Auralizer is an ambisonic convolution reverb built on top of the EVERTims auralization engine. It takes IRs of the EVERTims system of room modeling (which has also been modified to do so) and allows the user to use them in their DAW of choice. 



### xml Presets
The interaction between the Auralizer and EvertSE is made by a shared directory with XML files and impulse responses.

These presets are stored at `~/Documents/auralizer/presets/`, each in individual directories. For instance, if a preset were called `long_hall`, the IRs and .xml file would be stored at `~/Documents/auralizer/presets/long_hall/`. 

#### creating and modifying .xml preset files

The modified version of EvertSE is configured to save IRs in such a way that they can be read by the auralizer, along with relevant xml files. The auralizer is configured to load these presets into the processor values.

The attributes of this .xml file are as follows:

| attribute  | type   | value description                                                  | default value |
|------------|--------|--------------------------------------------------------------------|---------------|
| "name"     | string | The human-readable name of the preset                              | n/a           |
| "IRDir"    | string | The directory that contains the IRs -- often "."                   | n/a           |
| "wetAmt"   | double | The gain coefficient of the wet signal                             | 1.0f          |
| "dryAmt"   | double | The gain coefficient of the dry signal                             | 0.0f          |
| "inAmt"    | double | The gain coefficient applied to the input signal before processing | 1.0f          |
| "outAmt"   | double | The gain coefficient applied to the output signal after processing | 1.0f          |
| "yawAmt"   | double | The yaw value for the ambisonic processor                          | 0.0f          |
| "pitchAmt" | double | The pitch value for the ambisonic processor                        | 0.0f          |
| "distAmt"  | double | The distance value for the ambisonic processor                     | 1.0f          |
| "dirAmt"   | double | The amount of the direct path signal convolved with the input      | n/a           |
| "earlyAmt" | double | The amount of the early reflection signal convolved with the input | n/a           |
| "lateAmt"  | double | The amount of reverb tail convolved with the input                 | n/a           |

This table is shared between the auralizer and the modified version of EvertSE. 