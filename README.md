<h2 align="center"> Rokoko Studio - Sample project for Unreal Engine</h1>

[Rokoko Studio](https://www.rokoko.com/en/products/studio) is A powerful and intuitive software for recording, visualizing and exporting motion capture.

This sample project for Unreal Engine contains necessary means to get you started with your application.

---

## Getting Started

To learn more about how to use Virtual Production in Rokoko Studio, read our guide [here](https://rokoko.atlassian.net/servicedesk/customer/kb/view/861208607)
(Outdated link)

## Documentation

### Finger animation setup on character's with Live link 2.0 and Smartgloves

Live link 2.0 now supports the new Rokoko Smartgloves in Unreal Engine 4.25 and Rokoko Studio version 1.18.0b(234)

**Making sure the model is ready for live link 2.0**

Before importing your model into Unreal Engine. Make sure that the character's hands and fingers are modeled as close to the Newton model as possible, to get the best possible retargeting of finger animation. The fingers should be straight and the thumb pointing 45 degrees away from the other fingers.

<img src="Images/newtonHand.PNG">

Live link supports up to a 4 finger joint setup: Metacarpal, Proximal, Medial and Distal finger joint.

<img src="Images/newtonHandTop.PNG">

**Getting the plugin to work manualy**

For the plugin to work at its current state you need this development buid of Rokoko Studio: [https://developer.cloud.unity3d.com/share/share.html?shareId=-koPxa5S4I](https://developer.cloud.unity3d.com/share/share.html?shareId=-koPxa5S4I)

Then you need to download the Live link 2.0 plugin and install it manualy by moving it into your Unreal project's **plugins folder:** [https://github.com/Rokoko/rokoko-studio-live-unreal-engine/tree/4.25_jsonv3/Plugins](https://github.com/Rokoko/rokoko-studio-live-unreal-engine/tree/4.25_jsonv3/Plugins)

_Note: If your unreal project doesn't have a plugins folder, then create a folder called "Plugins"._

Now when you open your project a pop-up error will appear. Click yes to it and wait for it to build. If the building fails, you need to go into **Visual Studio Installer.**
<img src="Images/errorMessege.PNG">

Open up Visual Studio Installer and click on Individual Components. Then search for Unreal Engine Installer and install that. Now open the Demo project again and say yes to the pop-up and it should built.
<img src="Images/visualInstaller.PNG">

If it still doesn't work install theise optional packages under **desktop development with C++.**
<img src="Images/visualInstallerDownload.PNG">

When the unreal project is open, go into settings → Plugins and search for **Rokoko Studio Live** and make sure the enable mark is on. If you clicked enable you have to restart the urneal project. 

**Setting up the character inside Unreal Engine 4.25**

When the character is imported into Unreal Engine. Right-click on the **character** **skeletal mesh** and select **Create** and then **Anim blueprint.** Name it character_AnimBP and then open it. 

Inside the anim blueprint create a "**Rokoko body pose**", "**Component to local**" and a "**Rokoko Face Pose**" node. Connect them in that order and then to the **Output Pose.**
<img src="Images/animBPSetup.PNG">

Now click on the **plus** next to variables and change the variable type to **Name** and the variable name to **Rokoko Actor Name**. Then drag it out into the animGraph and chose **Get Rokoko Actor Name**. Connect it to Rokoko Body Pose and the Rokoko Face Pose.
<img src="Images/animBPVariable.PNG">

Right-click on the content browser and navigate to miscellaneous and create a **Data Asse**. Name it something like **character_BoneMap.** Now open it and write the names of the corresponding joints in the hierarchy. (If you use the same joint naming on more characters you can reuse this data asset)
<img src="Images/dataAsset.PNG">

When the BoneMap is done open the AnimBP again and click on Rokoko Body Pose. Then you can click on the **Bone** **Map Overwrite** and chose your Data Asset.
<img src="Images/boneMapOverwrite.PNG">

Now add the character skeletal mesh to the scene and navigate to the details panel and pick your animBlueprint under **Animation → Anim Class.** Then under Place Actors search for **Smartsuit controller** and **Smartsuit Reciever** and drag them into the scene. Click on the S**martsuit Receiver** in the **world outliner** and change the Streaming Data Port to **14043.**
<img src="Images/smartSuitReciverSetup.PNG">

To enable Rokoko Studio, go to Window → Live Link and under **Source** click on R**okoko Studio Source** and choose **Studio**.
<img src="Images/UELivelinkTap.PNG">

**Setting up Rokoko studio for live link 2.0** 
When the scene is open and the suit is paired up with a profile. Go to **Start Live Stream.**
Then navigate to **Custom** and click on the cogwheel. 
Now change the port to **14045** and change the Data format to **JSON v3**. Then click on the little slider beside the port number.
<img src="Images/studioSetup.PNG">

**Show the Rokoko Studio UI inside Unreal Engine**
In the content browser, click on **View Options** and enable **Show Plugins Content.** Then in the content view find **Widgets** under **Smartsuit Content**, and drag it into the scene. This will enable the UI when streaming from Rokoko Studio.
<img src="Images/recordingWidget.PNG">

Inside Unreal Engine click **Play** and the suit and gloves should be setup with live link 2.0, from Rokoko Studio.
<img src="Images/fingerShowcase.PNG">


# Old Documentation

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

For more information of how to setup Virtual Camera refer to Unreal's guide: https://docs.unrealengine.com/en-us/Engine/Plugins/VirtualCameraPlugin

### Live Link and Smartsuit Pro support

Smartsuit Pro data can be used with Live Link. With the Studio source enabled in LiveLink, when you have live Smartsuits Pro, you will see them by their IDs, (E46 in the picture).

<img src="Images/LiveLinkSmartsuit.png">

The data coming from the Smartsuit Pro subjects, can be applied directly to our character located in our plugin (Smartsuit Content/Mesh/Newton/newtonalpha) using the Live Link Pose animation node and  the Retarget Asset NewtonAlphaLiveLinkRemap.

<img src="Images/LiveLinkSmartsuit_anim_1.PNG">
<img src="Images/LiveLinkSmartsuit_anim_2.PNG">

You can in play mode now see the character animated through Studio and Live Link.
<img src="Images/LiveLinkSmartsuit_anim_3.PNG">

The skeleton hierarchy is setup in the following way:

 - Base
 - - Hips
 - - - Spine
 - - - - Spine2
 - - - - - Neck
 - - - - - - Head
 - - - - - LeftShoulder
 - - - - - - LeftArm
 - - - - - - - LeftForeArm
 - - - - - - - - LeftHand
 - - - - - RightShoulder
 - - - - - - RightArm
 - - - - - - - RightForeArm
 - - - - - - - - RightHand
 - - - LeftUpLeg
 - - - - -LeftLeg
 - - - - - - LeftFoot
 - - - RightUpLeg
 - - - - RightLeg
 - - - - - RightFoot

The NewtonAlphaLiveLinkRemap asset, remaps the following bone names:

Spine2 → Spine4

LeftUpLeg → LeftThigh

LeftLeg → LeftShin

RightUpLeg → RightThigh

RightLeg → RightShin

### Blueprints

#### Character animation blueprint example

To animate a character you have to use the nodes "Get Smartsuit Controller" and "Smartsuit body pose". In Smartsuit body pose you have to map the bones of your character. 

<img src="Images/BlueprintCharacterAnimation.PNG">

## Issues

File a bug in [GitHub Issues](https://github.com/RokokoElectronics/rokoko-studio-unreal-sample-project/issues)

## License

Copyright (c) Rokoko Electronics ApS. All rights reserved.

Licensed under the [GNU GPLv3](https://github.com/RokokoElectronics/rokoko-studio-unreal-sample-project/blob/master/LICENSE.md) License.



