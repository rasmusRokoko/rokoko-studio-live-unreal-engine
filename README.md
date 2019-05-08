<h2 align="center"> Rokoko Studio - Sample project for Unreal Engine</h1>

[Rokoko Studio](https://www.rokoko.com/en/products/studio) is A powerful and intuitive software for recording, visualizing and exporting motion capture.

This sample project for Unreal Engine contains necessary means to get you started with your application.

---

## Getting Started

To learn more about how to use Virtual Production in Rokoko Studio, read our guide [here](https://rokoko.atlassian.net/servicedesk/customer/kb/view/861208607)

## Documentation

### Example Map

Content/SmartsuitAndPropsExampleMap

### Components

#### Smartsuit Receiver

A Smartsuit receiver can be added from the Modes panel. This component is required to receive data for character animation and virtual production.

| Parameter  | Description |
| ------------- | ------------- |
| Smartsuit -> Streaming Data Port  | The port that will be used to receive data from Studio for character animation (Smartsuits). This port needs to match Studio's data streaming forward port.  |
| Virtual Production -> VPListen Port  | The port that will be used to receive data from Studio for virtual production props and trackers. This port needs to match Studio's data streaming forward vp port.  |

<img src="Images/SmartsuitReceiver.PNG">

#### Smartsuit Controller

A Smartsuit Controller can be added from the Modes panel. A Smartsuit Controller will bind to a Smartsuit and make the data accessible for animating a character.

| Parameter  | Description |
| ------------- | ------------- |
| Smartsuit -> Auto Connect  | If this is checked, the Smartsuit Controller will bind to the first Smartsuit that will appear in Smartsuit Receiver. Otherwise the Smartsuit -> Suitname will be used to bind to a Smartsuit with that name. |
| Smartsuit -> Suitname  | The name of the Smartsuit the component will bind to.  |
| Smartsuit -> Index Identifier  | An ID that can be used to access this Smartsuit Controller from blueprints.  |

<img src="Images/SmartsuitController.PNG">

#### Virtual Production Prop

You can add this component to any Actor in the level through the Add Component menu in the Details. This component will move and rotate the Actor based on the prop position and rotation. For this to work the Transform must be marked as Moveable.

| Parameter  | Description |
| ------------- | ------------- |
| Virtual Production -> Name  | The name of the prop to bind to. The name should match one of the prop names as defined in Studio. |
| Virtual Production -> Is Live  | If this toggle is checked, the prop will bind only for Live Props. If it is not checked, it will bind on playback props. This is used now to avoid conflicts when there's a playback with the same prop names as live.  |

<img src="Images/VirtualProductionProp.PNG">

#### Virtual Production Tracker

You can add this component to any Actor in the level through the Add Component menu in the Details. This component will move and rotate the Actor based on the prop position and rotation. For this to work the Transform must be marked as Moveable.

| Parameter  | Description |
| ------------- | ------------- |
| Virtual Production -> Name  | The name of the tracker to bind to. The name should match one of the tracker id as defined in Studio. That is a numerical value. |
| Virtual Production -> Is Live  | If this toggle is checked, the tracker will bind only for tive trackers. If it is not checked, it will bind on playback trackers. This is used now to avoid conflicts when there's a playback with the same tracker ids as live.  |

<img src="Images/VirtualProductionTrackerComponent.PNG">


### Live Link and Virtual Camera support

Virtual production props can be used with Unreal's Live Link and Virtual Camera plugins. To connect VP data into Live Link, open the live link panel and select Rokoko Studio Source -> Studio. You can only add this source once.

<img src="Images/LiveLinkStudio_1.PNG">

The source subjects (props and trackers) will appear in Play mode and they will be updated to reflect the data forwarded from Studio. When the play mode ends, the subjects are removed. That is because the plugin only receives data from Studio in play mode.

The names of the subjects have the following patterns:
- for live props -> prop:L:propname
- for playback props -> prop:P:propname
- for live trackers -> tracker:L:X
- for playback trackers -> tracker:P:X

<img src="Images/LiveLinkStudio_2.PNG">

Having the Live Link plugin enabled we can now use a prop to control Unreal's virtual camera by setting the Live Link Target to the subject name of interest and Input Source to "Live Link"

### Blueprints

#### Character animation blueprint example

To animate a character you have to use the nodes "Get Smartsuit Controller" and "Smartsuit body pose". In Smartsuit body pose you have to map the bones of your character. 

<img src="Images/BlueprintCharacterAnimation.PNG">

## Issues

File a bug in [GitHub Issues](https://github.com/RokokoElectronics/rokoko-studio-unreal-sample-project/issues)

## License

Copyright (c) Rokoko Electronics ApS. All rights reserved.

Licensed under the [GNU GPLv3](https://github.com/RokokoElectronics/rokoko-studio-unreal-sample-project/blob/master/LICENSE.md) License.
