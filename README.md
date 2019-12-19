# auralizer

Auralizer is an ambisonic convolution reverb built on top of the EVERTims auralization engine. It takes IRs of the EVERTims system of room modeling (which has also been modified to do so) and allows the user to use them in their DAW of choice. 

The auralizer now uses the ambisonic panner from libspatialaudio to modulate the source's orientation. This will need to be improved because it seems stuttery and not particularly musical. 

For anyone interested in working on this/sharing ideas to work on this, feel free to get in touch! I'd love to ehar your thoughts and see if I could make them happen.

I'm also working on some algorithmic ambisonic reverbs, which could be a fun addition to this. 


### To do:

* Put all the sliders in an array and address them through an enum (this will help when updating the UI)
* Make an init preset which is loaded automatically upon launch
* Redo the processor so that it conditionally compiles into mono-mono, mono-stereo, stereo-stereo (eventually, we may do more than that because we hyphothetically can do basically anything with the HOA internally processed signal)
* Make maybe 30-40 presets
* Make a preset loading system which lists all presets in a dropdown instead of using fileChooser
* Make an installer for non-dev users, distribute binaries
* Add IR reversal
* Add IR scaling (time/pitch stretching) possibly independantly through the stored STFT of the IR
* Add binaural output DSP
* Add virtual microphone DSP w/ some basic filtering and waveshaping
* Create new UI which has distance, binaural vs speaker array output, (zooming?), and maybe some more
* Make custom UI objects for 3d panning and distance rendering
* Offload the IR rendering, modulating, and regenerating systems to a separate header


<br/>

### xml Presets
The interaction between the Auralizer and EvertSE is made by a shared directory with XML files and impulse responses.

These presets are stored at `~/Documents/auralizer/presets/`, each in individual directories. For instance, if a preset were called `long_hall`, the IRs and .xml file would be stored at `~/Documents/auralizer/presets/long_hall/`. 

##### creating and modifying .xml preset files

The best way to create .xml preset files is in EvertSE. It would be nice to save room geometries with presets so that they could be recalled in both Blender and EvertSE, but this would take up more space than is necessary for most users, and superusers can save blender environments themselves to update later. 

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