#include "bot.hpp"

void    creatorsCmd(Client &client, std::string &string) {
	(void) string;
    std::string guigui("PRIVMSG #bot :                                                                          gozsertt:\nPRIVMSG #bot :\nPRIVMSG #bot :@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&&&&@@@&&@&&##&&&&&&&&&@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&%%#(/***///((((((#%%%%%%%%%%%&%%&%\nPRIVMSG #bot :@@@@@@@@@@@@@@@@@@@@@@@@@&@@@@@@@@@@@@@@&&##&&&&&@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&%%%%%#/,,,,*******///((((###%%%%&%%%%\nPRIVMSG #bot :@@@@@@@@@@@@@@@@@@#%&@@@@@@@@@@@@@&&#%@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&%&%%%%%%##((/**,,,**********///((#####%%%\nPRIVMSG #bot :@@@@@@@@@@@@@@@@@@@@@@@@@@@&%#%&@@&&&@@&&@&&@&&&&&&&@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&%%%%%%###(////((((/////***,*************//(((##\nPRIVMSG #bot :@@@@@@@@@@@@@@@@@@@@&%%&&&@@&@@@&@&&&@&&&&&&&&&&&&&&/,.%&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&%%%%%##(/(*/((((((((((//***///(((((((((///*******/////\nPRIVMSG #bot :@@@@@@@@@@@@@&&%%&@@@&&@@&@@@@@@&&@&&&&&&&&&&&#.........../&&&&&&&&&&&&&&&&&&&&&&&&&&&&%&%%%%##((*//((((((&(////(((((((((((((#######((((//////(((/////\nPRIVMSG #bot :@@@@@@@&%&@&@@&@@@@@@@@@@@&@@&&&&&&&&&&&&%....................@&&&%%(((#((%%%&&&&&%%#((//*//(////(((///(##(#####(###########((/(((/(#%%%%%%%%%%%%%%###\nPRIVMSG #bot :&&&@@@@@@@@@@@@@@@@@@&&&&&@&&&&&&&&&&*.,....................,.,/*/(((##%%((##///(///(////****//(((((###(####(***(((///(((#%%&&&%%&%%%%%%%%%%%&%%%%%%%%\nPRIVMSG #bot :@@@@@@@@@@@@@&&&&&&@@&&&&&&&&&&&#........................,/%&&#%%%%%%%%&&&&%%##(***,,***,*/((((((((/***/(*//((#%&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\nPRIVMSG #bot :@@@@@@@@@@@@@@@@@@@@&@@&&&&&.................(%%.......*%%%%&&&&&&&&&&&&&&&&&&%%%(/(((((//,///#/((((%&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\nPRIVMSG #bot :@@@@@@@@@@@@@@@@@&@&&&&,,..............*#%%%%%%%......,(%&&&&&&&&&&&&&&&&&&&&&&&&%%(//((#%&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\nPRIVMSG #bot :@@@@@@@@@@@@@@&&&&#..,............*#%%%%%%%%%%%(..... .#%&&&&&%%%%%%%%##%%%&&&&&&&#((#&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\nPRIVMSG #bot :@@@@@@@@&@@@@%.,,,..........,(&%%%%%%%%%%%%%%%%....   /%&&&&##%((((((///////(((#&&%##%%&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&%&&&&&\nPRIVMSG #bot :@@@@@@&&%*,,,,,,,......*#%%%&%%%%%%%%%%%%%%%%%%. .     %&&%(((((((((///////////*/#&%,.&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\nPRIVMSG #bot :&&&&#,*,,,,,,,.,..*%%%%&&&&&&&&&&%%%%%%%%%%%%%%. .     %&%(/////////////////////,,#.     %&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\nPRIVMSG #bot :&&&*,,,,,,,,,(&%&&&&&&&&&&&&&&&&&&&&&%%%%%%%%%% .      *%%///(%%#%%&&%#((%%&&&%&*,/         *&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&%&&&&\nPRIVMSG #bot :###,,,,*#%&&&&&&&&&&&&&&&&&&&&&&&&&&&&&%%%%%%%#       ((#%*/(##%%#&%%#(//#%##&&%(,/         .&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&%&&&&&&\nPRIVMSG #bot :#%%,,%&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&%%%%%%.       ##%/**///((((((((////(((//*,#         .&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&%#//*////\nPRIVMSG #bot :,,,,,*/%%%&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&%%%%%%        ,##(////////(((/////((///**,(         ,&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&%%%%%%%%%#(/**,,,\nPRIVMSG #bot :((,,///(#%%%%%%&&&&&&&&&&&&&&&&&&&&&&&&%%%%%%%          /#%(((((((((#%&&&%(/((///*,         (&&&&&&&&&&&&&&&&&&&&&&&&&&&%%%%%##(////(((((((((((((((((#\nPRIVMSG #bot :&&,,(/(((##%%%%%%%%%%%%%%%%%%%%%%&&&&&%%%%%%%%            %%%#(((%&&%%%#%%%&&((((#%&&&%%#/  %%%&%%%%&%%%%&##((/////(//*///(((//******/((#((######(((((\nPRIVMSG #bot :&*,*((((((###%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%(          #&&&&%%###(#%%####((#((#%&&&&&&&&%# ********/(%%&%(,,,,,,*/(((((((/***//((/(#&&&&&&&&&&&&&&&&&\nPRIVMSG #bot :(,,/((((((((((##########((((###(((#((((((((((        (%%@@@@&&&&&%((((((((((#%&&&&&&&&&&%#(               .*(#%%&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\nPRIVMSG #bot :#,,(///////////////////////////*/************        .%&&&&&&(%@&@&&&&&&&&&&&@@&&&&&&&&&&%% &&&&%%%%%%%%%%%&&&&&&&&&&&&&&&&&&&&&&&&&&&&%%%&%#(,,,,,,,,\nPRIVMSG #bot :,,*//////////////////////**************,,,,..         *&&&&@@&(##%&@@&&@@@@@@@@@@&&&&&&&&%( &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#*,....................,,,,,\nPRIVMSG #bot :,,///**************************,,,,,,........         %&&&&@@@&#(###%%&@@@@@@@@@@@@@@@@@@&%%###%&&&&%%%%/*.......  ...........................,//(###*\nPRIVMSG #bot :,./************************,,,,,,,..........        .&&&@@@@@@@@&#&@@@@@@@@@@@@@@@@@@@&&%%%%%%%%#####/.. .................,*/(#(((((((###############*\nPRIVMSG #bot :,,****************,,,,,,,,,,,,,,,...........    ##&&&&@@@&@@@@@@@@@@@@@@@@@@@@@@&&&&&&&&&&&&&&&&%&&&&&&#(#%%%%%%%%%%%%%#####(((((((((#############(##/\nPRIVMSG #bot :,**************,,,,,,,,,,,,,,,,,............ %&@&&%&&&&&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&&&&&&&&&&&&%&&&#(%%%%%%%%%%%##((((((((((((############((#/\nPRIVMSG #bot :.(**************,,,,,,,,,,,,,,,,...........#@@&&@@@&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&&&&&&&&&&%%(######%%%((*,,,*****//#%%%%%%%%%%%%%%#\nPRIVMSG #bot :*//**************,,,,,,,,,,,,,,,..........#&@@@@&&&@@@@@@@@@@@@@@@@@@@@@@@@@&&//#@@@@&@@@@@@@@@@@@&&&&&&&&&&&&&&%%/,,,,,,%%%#######((((#%%%%%%%%%%%%%#\nPRIVMSG #bot ://///**************,,,,,,,,,,,,,,.,.......&@@@@@&@@@&&@@@@@@@@@@@@@@@@@@@@*,.%&&&%&&(. /&&@@@@@@@@@@@@@@@&&@@&&&&&&&#,,,,///***,,.................****\nPRIVMSG #bot :(///////*************,,,,,,,,,,,,,,,.,...&&@@@&&@&@@@@@@@@@@@@@@@@@@@@@/,,,,,,,,@...%&&&&&&@@@@@@@@@@@@@@@@@@@@&@@&&&%&,,....... .................*,/%\nPRIVMSG #bot ://////////***************,,,,,,,,,,,,,,,,@@@@&&@@@@@&@@@@@@@@@@@@@@@@@@@@&&&,..%%,.*,,(@@@@@@@@@@@@@@@@@@@@@@@@@&@&&&&&%%%........................,,/(\nPRIVMSG #bot :(/////////////***************,,,,,,,,,,,/@@@@&@&&&&&@&@@@@@@@@@@@@@@@@@@@@@@@&&@&&&&&&&&@@@@@@@@@@@@@@@@@@@@@@@@@@&@@&&&&&&&&(  ..................,**/\nPRIVMSG #bot :((((/////////////*******************,,,,@@@@@&&&&&@@@@@@@@@@@@@@@@@@@&%#(&(#&&@&#((%&&@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&@@@&&&&&&&&(................,.,,*/\nPRIVMSG #bot :(((((((/////////////*******************,@@@@@&&&@@@@@@@@@@&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&&&&&%,............,,,,,**/\nPRIVMSG #bot :((((((((((//////////////**************%&@@@@@@&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&@@@@@@@@@@@@@@@@@@@@@@@&&&&&&%%&&@&#,,,,,,,,,***/\nPRIVMSG #bot :##(((((((((((///////////////*********&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&@@@@@@@@@@@@@@@@@@@@@@@&&@@@@@@@@&&@@&,,,***(&/**(\nPRIVMSG #bot :######(((((((((((///////////////////*/@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&%.,..,,.,,,,\nPRIVMSG #bot :########((((((((((((((///////////////%@@@@@@@@@&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&@@@&&&&&#,,,,,,,,\nPRIVMSG #bot :%###########(((((((((((((((//////////&@@@@@@@@@&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&@@@@@@@@@@@@&/@@@@@@@@@@@@@@@@@@@@@@@&&&&&&&&#,,,,,\nPRIVMSG #bot :%%%%%#############((((((((((((((((//(@@@@@@@@@@&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&@@@@@@@@@@@@@%....*@@@@@@@@@@@@@@@@&&@@@&&&&&&&&&#*,\nPRIVMSG #bot :%%%%%%%%%%###############(((((((((((#&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&@@@@@@@@@@@@@#...,,,,,&@@@@@@@@@@@@@@@@@@@&&@@@&&&&%\nPRIVMSG #bot :%%%%%%%%%%%%%%%%####################%@@@@@@@@@@&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&@@@@@@@@@@@@@(,,,,,,,,,,&%@@@@@@@@@@@@@@&@@@@@@@&@&&\nPRIVMSG #bot :&&&&&&%%%%%%%%%%%%%%%%%%%###########&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@/,,,,,,,,,,&&&&@@@@@@@@@@@@@@@@@@@@@@@&\nPRIVMSG #bot :&&&&&&&&&&&&&&%%%%%%%%%%%%%%%%%%%%%%%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@,,,,,,,,,,,&&&&@@@@@@@@@@@@@@@@@@@@@@@@\nPRIVMSG #bot :&&&&&&&&&&&&&&&&&&&&&&&&%%%%%%%%%%%%&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@,,,,,,,,,,,&@@@@@@@@@@@@@@@@@@@@@@@@@@@\nPRIVMSG #bot :&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@,,,,,,,,,,,&&&&@@@@&@@#/%@@@@@@@@@@@@@@\nPRIVMSG #bot :@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@,,,,,,,,,,,&&&&@@&&@@@#**/%@@@@@@@@@@@@\nPRIVMSG #bot :@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*,,*(%&@@@@@@@,,,,,,,,,,,&%%&&&@@@@@(***/*(&@@@@@@@@@\nPRIVMSG #bot :@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*,,**,********/%&@&&&(,,,@@@@@@@@@@@(***////(%%@@@@@@\nPRIVMSG #bot :@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@((/(@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@(*************,,,,,..,....,.,,,*(%&@@(///(((((((#&@@@\nPRIVMSG #bot :@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&#&((((&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&#*,,,,,,,,.,,,,,.........,,,,,,,,,,,,,,,,******/#&(&@\nPRIVMSG #bot :@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%(#(//%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&..,,,,,,,,,,,,,,.....,,,,,,*******//****/****/*/////\nPRIVMSG #bot :@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%#//%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@,..................,,,,,,,,,,,*(%%#(/(((((((///////(\nPRIVMSG #bot :@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%%&((/%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&@#********......,,,,,,,,,,,,,,,,,,*,***********////((\nPRIVMSG #bot :@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&@@(%(&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&/**#(,...,,,,,,,,,,,,,,,,,,,,,,*************////////\nPRIVMSG #bot :@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%%%##@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%*/**,,,,,,,,,,,,,,,,,,,,,,,,*************/////////((\nPRIVMSG #bot :@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%##%#%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%//////////////*,,,,,,,,,**************//////////((((\nPRIVMSG #bot :\n");
    client.bsend(guigui);
    std::string noam("PRIVMSG #bot :                                                                          nabitbol:\nPRIVMSG #bot :\nPRIVMSG #bot : .  ,*        %.   .,.,  ..   . ..., ,    * (( .#. /../.,(# *%%%%#%%&&%%*%%#*#%**%&&&%%%%% , ,((,( %,..#%%&%&   # ,#%%(##%#%&% ,    ./ ,. ..*...      \nPRIVMSG #bot :...  ...  .,. . (...,/*.,..  ...., ,* *,. . .* *. ..,/.,,/#%*#%%%%%&&#&%%%%%/.%%&&&&&%&.,(* /(  (#(*%%%&,%#%* ,*%&%%%%(,.#%%((%#   ...%#*..,.. .    . \nPRIVMSG #bot :        (%.. * *      .  ,,( . ,.   .*.(,* .,*/*(%.(%%%%%%&&&&&&&&&%&&%(%&%%%%#%#&&&%(#,.*,.*.(%#%%%&%#%%/,/.%%%%%%(   ##%/.  ..%# /../,.,...%( ....  \nPRIVMSG #bot :        , /# .     * .**/((  . .. ., ,. / .*,*/((%%%&&&&&&&&&&&&&&&&&&&&%%%%%%%&&%&#.*..../#%%%%%#((%%%####%%&%..(..%%%&  .***     ####  .* . ..,*#( .\nPRIVMSG #bot :     ..(%%*   ./  ..  ,*.* .. ,,,#%( * /,.**.%&&&&&&&&&@&@&&&&&&%&%&&&&&&&&%%%%&&&#*%%,#%%#%%%%#####%/#,%%%&%((#//#%%* ,%,  ,/  ,     ( ,%#.. /.  . , \nPRIVMSG #bot :.(*  *.%%# %,*. ..//  .. ,/%///.(*, (%(.(.,%%%&&&&&&@&&@@@&&&&&&&&@@@@&&&&&%%%%%%%%%%&&&#%###%#&%#&&%#%%&&//%# *#%%%/#    %.* . */    , .##*,.,/.,  * \nPRIVMSG #bot :,%/%*, %#&&/. *,(####, . ...   ( //*& /#&&&&&&&&&&&@@@&@@@&&&&&@@&&&&&&&&&&&&&%%%%%%/%%(%&#&&%%#%&%/%%%%#%#(*/%#%%%*    . .,.%. ,   (  //%  (     /   \nPRIVMSG #bot :%%%##/%#%%%%&#%&/((.,  . (/(*  *// /#%&&&&&&@@@@&&&@@@@@@@&&&&&&&&@&&&&&&&&&&&&%%%%(%(#%#*%%#%(%&%%%&#(#%%%(%%%%/. ( ....,/ ,, #.. ..,#, /.  /#    .. \nPRIVMSG #bot :#%&&*%%%&%%#&&%&   ..,*            &&&&&&&&@@@@&@&&&&@&&&@@&&&&&&&&@@@&&&&&&&&&&%#%#(%%###(%*%%#%%&#(%/(/(%%&&(#(//((/(,../     #*  . * ###     .*.(( \nPRIVMSG #bot :   %(%&&&&,/%&&&&% (%%.,* . ,   .#&&&&&&@@&&&%%%%&&&%%%%%%&&&&&&@@@@@@&&&&&&&&&&%%%%%%&%##/%&&%%%%%%%,, #%%&%#%%%####/(/(#/(,,...% .**, ,#.,   .(.,,/,\nPRIVMSG #bot : ,*/(#%&&&&@&&&&&&&&&%%#/,.(. ,*%&&&&&&&&&&%(//((((///*///((#%%%%%&&&@&&&@@@@&&&&&%%(%&%#%%&&&//%##%%%%%%%%#%##%#(%####/#(##((.*./*%#,..  #.... .  ..*\nPRIVMSG #bot :#%%&%&&&&(%&%%(&&&@@&&&%%%%%%%%%#&&@@@&&&&%(/***************//(((((###%%&&&&&&@@&&%%%%%%%&&%%&&&%#%%#%%%######(#####%((*((%##(/(*. (/%.*,  # *.  ,. ((\nPRIVMSG #bot :&@@@&&&&&%*%#&&&&&&&&&%%%%%&&%%%&&&&&&&&&%##/*****************///////(((((#%%&@&&&&%%%&&%&#%%&#%%##%%%&%%%%#%%%%%####%%/(/#((/#&%%%%##&%%%#%%*.#/,. . \nPRIVMSG #bot :@&&&@@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&%##(/*****************////////////((%&&&&&&%&&%#%%%%%%##%%%#%#%((#%%&&%%##(#%##/(#####%*#((%***% *%# .**.*, *\nPRIVMSG #bot :%#,(%&@@@&&@&@&&&&&&&&&&&@&&@&&&&@&&@&@@&%#((//****************/*/**/////////#&&&&&&%%%%%%%#%#%%%&#%%##((##%%###%#%#&&%%%##%%(,.(/(%######//((#(*.* ,(\nPRIVMSG #bot :&&&&@&&&@@@@&@&&&@&@@@&&&&&&&&&&&&@@&@@@&%((//***********************///////(#&&&&&&%%#&%##%%%%%##%%#%#%(###%%####%####%###&&%/%#.%#(#(%/((%#,/*%((%%%\nPRIVMSG #bot :&&%&&(#@&&&&&&&&&&&&&&&%&@&&@&&&&&@&&@@&#(////***************************///(%&&&&&%%###%%%&%%%%%%##&%%%((%#%%%%(%%&/((###%(&%%(#%/,#%**#(%((  ,%##*%(\nPRIVMSG #bot :&@@@&&&&&&&@&&&&&&&&%&&%%%&&%&&%//&@&@@#//(/(####%%%&&%(//******//////////*/(%&@&&&##%%%&&%%%%%%%%%#%%%%%##&%%%%######%%%%##%##&%#%##*(*,.. ..#/.  #**\nPRIVMSG #bot :@&&&&&&&&&&&&@@@&@@@@@&&&&&&%&%/%#%%&@&(///(((#%&%#%&&%###(/**/(#%&&&&&&%%##((@@@&%%%%%%%%%%%%%%%%%%%%%%%&%%#%#%###%%%%%%%%%%#%#%%((#.../. ./(..  .,, \nPRIVMSG #bot :&&#%&@@@@@@@@@&@&&&&&&&&&&&&@@&/#**//#&/////((###&&&(#%##(/***/(%&&@@&&%&%%##(&@%*%#%%%%%%%%%&%&&&&#%%%%&%%%%%%#%%%%%%(%%(%#%###&#&%%#*#**##*( ,,/.//.\nPRIVMSG #bot :&&#&&@@@@@@@@@@@@@@@@@@##&&&&&&///(##/(////****/(((((#((///****(#%#%#(#%%%#(((&(%###%%%&%&&&&&&%&%&&&&&&&%%%%%%%%%%%%%%%%%###%%(#%#*/*#**((%%#%##%/**,\nPRIVMSG #bot :&&&@@@@&@@&@@@&&&&@@@@@&@@@&@&&(//(***(///*********/***********/(#((((((//////(*/(%&%%%%&&&&%%&&&&&&&%%&&%&&%%%%%%%%%#%%##%%((%%%&%,(*(%((%##(/%%%.*.*\nPRIVMSG #bot :&&&&@@@&&@@&@@@@@@@&@@@@&@&&&&&&*/**//#///**********************/////******///##(#&&&&&&&&&&&&&&&&&&%@&&&&&%&%%%%#%%%/%(/((%#(((/*( .,,*(%##%#((##(%%#\nPRIVMSG #bot :#%&@@@@&&@&&&&&&&@@@@@@@&&&@&&&&&*****#(///**********************///*//***///(#(/&&&&&&&&&&&&&&&&&&&%&&&&&&&&&&#%%%(.&%&#,*,(**,*..*(##%#%%##%#%%%%%%#\nPRIVMSG #bot :#%&&&&&&@@@@&&&&&&&@@@&&&&@@&@&&&&#***#(////**********/**********///**///////(/*/&&&&&&&&&&&&@&&&&&&&&&&&&@&&&%&&%&%%%&%#/(#.*.(#*(*(#&#(#%#%%##%%####\nPRIVMSG #bot :&%%%#@&&@@@@@@@@@@@&&@@@&&@@&&&&&&&&&&&#(((/***********/###((((##((//***//(/(///%%&&&&&@&&&&&&&&&&&&&&&&&&&%%%&&&%%(#&%(.%..**/(###%###%%%(##%%##%%###\nPRIVMSG #bot :@%#(#%&&@@@@@@@@@@@@@@@@@&&@@&&&&@@&&&&%#(((//**********////((((////****//(#%%&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&%&&&&&&%%%%%.*,,#%%%(%###%#%###%##%#%%%%%%\nPRIVMSG #bot :&&&&#%&&&&@@@@@@@@@@@@@@@@@&@&&@&&&&%%&&%#(((//////(//****//**/////***//((##%%%&&&&&&%&&&&&&&&&&&&&&&&&&&&&&&&&%%%%%%%&/#/,#(/%%#%%%%#%#%#####%%%%%%%&\nPRIVMSG #bot :#(#((/&&#%#&%@@&&@@@@@@@@@@@@@&&&&&%(/*(/%##((/////*(((##%###%%#/(((///(##%&&&@&&&&&&&&&&%...#&&&&&&&&&&&&&&&&&&&%%%%%&%#%%%####%%#%#%%%%%%%%%%%%%%%%%\nPRIVMSG #bot :%#(&&%&%&@%%%&@%&@@@@@&@@@@@@@@@&&(/(/#%(/%#(#(///***///////((((//(((((##%#####%(*/%%&&%......(%%&&&&&&&&&&&&&&&&%&#%%%&&%#####%%%%%%%%%%%%%%%%%%%%%%%\nPRIVMSG #bot :#(/&%&&%%&%##&&#%##%&&&&@@@@@&&&&%#(#####//(%#((///**//((####((((((((##%(&%%%%%%%%%###,.,**,,.,%%&&&&&&&&&&&&@&,...,#%%%&&%%%##%#%%%%%%%%%%%%%%%%%%%%%\nPRIVMSG #bot :&%%&&&&&&&%%%&&&&&&&&&%%%%##&&&%&%(###%##////#%#(//**********////((####(@@@@&&&%%%%%#.,*//**,.,(##%%%&&&&&&&%...,,,.,%&&%%#%#,.*(%%(/,%%%%%%%&%%%%%%&&\nPRIVMSG #bot :%%&&%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%#%%%%%//////#%#(////**///*////(#%%((/@@@@@@&&&&%(.,*/(/*,...,(%%%%%%%%%#*.,,,***,./%#*.*#/,%%%(#/##(((#,(&#%(/*##/%\nPRIVMSG #bot :%%%%%%&%%%%%%%%%%%%%%%%&&&&%%&@&&@@@&%%#*///////((#%%#(((((((###%%##((((%@@@@@@&&%*,.,*(//*,...,***,,(%%%/,.,,**//*,,*/******/#*(&%&###//*..%,#((/###(\nPRIVMSG #bot :&&&%%%%%%%%%%%%&%%%%%%%%%%%&&@&@@@@&&((***///*/*//((((##%%%&&%%%###(((//(@@@@@@&/,..,,/*/*********/****/,...,,,///*,,,//***************/(%*/%(,**#%((/\nPRIVMSG #bot :%%%%##((((%%%%%#(//////%&&&&&&@@@@@&&******//****/////(((((((((((((////(%@@@@@@@@,..,,***//(((((((((/***/*,,,,/(/**,.,/%%%%&&%&&%(&%*****%%/%,*,**,/(*\nPRIVMSG #bot :%%%%%%&&#/////////**(&&&&&&&&&@&@@@@@@%/****/*******/////////((////////(&@@@&@&*...,,**///((#(//((((((/***/,,/(//*,,.,,/###%%%%%%%%&*****&*##********/\nPRIVMSG #bot :&&%(////////*/**//(&&&&&&&&&&&@&@@@@@@@&(,,******************/////////(%@@@&%/,,,,,,***,,/(/**(#((///////***//*/,,,..,,#/,,,,,,,/##%%%%%%####((/((((((\nPRIVMSG #bot :#(/////////////(&&&&&&&&&&&&&&@&@@@@@@@@/&*,,*************************/&@@@&@%***/(((*..,//*,(((/************,,,*,...,(#######%###%%##%%##%%##########\nPRIVMSG #bot :///////////////#@@@@@@@&&&@&@&@&#@@@@@@@@%@&*,,**,,,**********,,,,****&&&@&&&%/((**,,...,#/*(((*,,**///*****,,,,.....*&&%######/################%%####\nPRIVMSG #bot ://////////#%&&&&&@@@@@@@&&&@@&@&,*@@@@@@@@&@@&*,,,,,,,,,,,,,,,,,,,,,/#&&@&&&&,,(/*&&/%,,#%((%(.....,/##(/*****,,,,..,(&&&%%%%%%%%%%%%%###########%##%%\nPRIVMSG #bot ://///%&&&&&&&&&&&@@@@@@@&@@@@&&/,*@@@@@@@@&@@@@@(,,,,,,,,,,,,,,,,,,/#&@@@&&&#,/(*,*%&#(#(####,,/((/****/##/*****,,,,,#&&&&&&###%%%%%%%%#%#####%#######\nPRIVMSG #bot :#&&&&&&&&&&&&&&&@@@@@@@@@@@@@&/**@@@@@@@@@@%&@@@@@&*,,,,,,,,,,,,,,/%&@@@&@&&,,*/*,,(*(*/#(/##(#&&&@&@&#(((#((/*,,,,,,/@@&&&&&%%%%%%%%%%%%%%%%%%%%%%#%#\nPRIVMSG #bot :&&&&&&&&&&&&&&@@@@@@@@@@@@@@@@&*@@@@@@@@@@@@@&&@@@@@@&#,,,,,,,,,,*&@@@@&&&&#,. ....,,*/*/**,*//**/*,,*((/*,...,,,,,,,,%&&&&&&&&%%%%%%%%%%%%%%%&%%%%%%%\nPRIVMSG #bot :/&@&&&&&&&@@@@@@@@@@@@@@@@@@&&&&@@@@@@@@@@@@@&*&@@&@@@@@&@/,,,,,/&&@@@@@&&#*,... .*/*,,......,*(,,,*(//**,.......,,,,,(&&&&&&&&&%%%%%%%%%%%%%%%%%%%%&%\nPRIVMSG #bot :&@&@@@@@@@&@@@@@@@@@@@@@@@@@@&&@@@@@@@@@@@@@@@@&&@@@@@&&&@@@@@@#&@@@@@@@&&/,.,..**,,..... .......................,,,,,/&#/*****,,,,(%%%#%%(%%%%%%%%%%%\nPRIVMSG #bot :@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&@@@@@@@@@@@@@@%&@@@@@@@@@@@&@@@@@@@@@&@%*..&&%%%&%#,........   ............,,,,,**,*******,**,,**,,%%%%%%%%%%%%%%%%\nPRIVMSG #bot :@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&@@@@@@@@@@@@#%@@@@@@&/@@@@@@@@@@@@@&/.,%@&@@@&%*,..........,,,,,,,,,,,,.,,,***,************,,,***#%%%%%%%%%%%%%\nPRIVMSG #bot :@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@(%(((&@@@@@@@@@@@@@@@#,,/#&&&%/*,,.......,,,,,,,,.......,,*/(***//************,*****%%&%%%%%%%%%\nPRIVMSG #bot :@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%%@@@@@@@@@@@@@@@@@@@@@(%%%@@@@@@@@@@@@@&@&&&%**#%&##(/**,,,,,**,,,*,,....,,,**/(///#(///********************%&%%%%%%%%\nPRIVMSG #bot :@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%&@@@@@@&@@@@@@@@@@@@@@,,&@@@@@@@@&&#*,**/*,*/*//*//***/*/*******,,,,,,/(#%%%#(/((/&#(///********************%%&%%&%(%\nPRIVMSG #bot :@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*@@@@@@@@&@@@@@@@@@@@@@*, &@@@@@&#*....,,,,*,,**(%(##&%/////((///(###&&&&##%%**(/#&&&#(///********************%%%%%%%%\nPRIVMSG #bot :@@@@@@@@@@@@@@@@@@@@@@@@@@&@&&@@@/@&@@@@@@&@@@@@@@@@@@@@@@@@@@@%*.........#(//(**/((/*/(&&@&@@@@@@@@@@@&&@*//*,(*//(////((///******************(%%%%%%\nPRIVMSG #bot :@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&@&.#@@@@@@@@&&@@@@@@@@@@@@@@@@@@(,......,**(*,*%&&&%&&&&%(,*///*/*(*/(@%(//(*/*,,,///(/////((((/(//****************%%%%&\nPRIVMSG #bot :@@@@@@@@@@@@@@@@@@@@@@@@@@&&@&@&(#&@@@@@@@&&@@@@@@@@@@@@@@@&&(.......***,*&&#%%&&%%%#%(*/(###%#####%@#,*//,,,,,//((#((/**(#//*********************#%%%\nPRIVMSG #bot :@@@@@@@@@@@@@@@@@@@@@%@&%&@#.....(#@@@@@@@@&&@@@@@@@@@@@@&&#,.....,*/,#&#*,,,#%/*,,%&/,.....,,,,***//(/(/(//(((((/(((//***//***********************/%%\nPRIVMSG #bot :@@@@@@@@@@@@@@@@@@@@@@.(&/&*.,#%%&@@@@@@&@&&@@@@@@@@@@@@@%/,.....,/#&**,.................. .........,,*(##(##(///(((///***//************************(%\nPRIVMSG #bot :@@@@@@@@@@@@@@@@@@@@@@@@.&/@@@@@@@&@@@@@@@@&&@@@@@@@@@@@%,......,%%(,..................................,,*((((((##(//****//**************************%\nPRIVMSG #bot :@@@@@@@@@@@@@@@@@@@@@@@@&.%@@@@@@@@@@@@@@&@&@@@@@@@@@@@&*,.....,,*,.......  .................... .....,,*///(((##(//***///***************************/\nPRIVMSG #bot :@@@@@@@@@@@@@@@@@@@@@@@&&.&%%%%%#@@@@@@@@@@@@@&@@@@@@&/,....,,****......... ........................,,*//////(##((/***//*****************************/\nPRIVMSG #bot :\n");
    client.bsend(noam);
    std::string tibo("PRIVMSG #bot :                                                                          tgontier:\nPRIVMSG #bot :\nPRIVMSG #bot :******************,***,,,,,,,,,,*&&%%&,,/*///***********//**///***//*****/**/////*////**********,,**************,*(**/////////////////////////////////\nPRIVMSG #bot :**********************,,,,,,,,,,*&&%%%,,/**///**////*******/*//////*///*****///*/*//*/**************************,*(**/////////////////////////////////\nPRIVMSG #bot :**********************,,,,,,,,,,*&&%%%,,/////*/******/******/////********/////**////****************************,,(*,***//////////////////////////////\nPRIVMSG #bot :******************,***,,,,,,,,,,*&&%%%,,/**/**/**//*//***/***/******/**/**/##(////////***********,**************,,(*,/////////////////////////////////\nPRIVMSG #bot :********************,,,,,,,,,,,,,&&%%%,,////***//************///(#%%%&%&&&&&%%&&&&&&%&&%//******,***************,*#***////////////////////////////////\nPRIVMSG #bot :****************,,**,,,,,,,,,,,,,%%%%%,,//**/*/*************%%&&%%&&&@&@@@&&@@@@@@@@@@@&@@&%(********************,(******/////////////////////////////\nPRIVMSG #bot :***********,,,*,*,**,*,,,,,,,,,*,%&&&%,*/*/**/*//*******//%%#&&@&&@@@&&&@@@@@@@@@@@@@@@@@@@@&&**/****************,(**////*////////////////////////////\nPRIVMSG #bot :*/********************,,,,,,,,,*,#%%%/,,,,,,,,****//*//%&##&@@@@@@@&@@&&@@@@@@@@@@@@@@@@@@@@@@&(*****************,(/****//////////////////////////////\nPRIVMSG #bot :**********************,,,,,,,,,*,#%&&&***************%&&&&@&&&%%###%%&&@@@@&&&@@@@@@@@@@@@@@@@@#(((***************(/****//////////////////////////////\nPRIVMSG #bot :*/********************,,,,,,,,,,,#####*,**///**//*/(&&&&&%#(/*********///(//(#%%&&&&&&&&&@&@@@@&%/(**************,/(**//*/////////////////////////////\nPRIVMSG #bot :**********/****,***,**,,,,,,,,,,,#%%%%**//////////#&&&%%(/******************,,,****/////(#%&@&&&%(/*********,,***,,/*******,,,,,,*****////////////////\nPRIVMSG #bot :*****************,,,,*,,,,,,,,,,,(####**/////***/#&&&%%(//*******************,*,,,***//////(&&&&&&&/*************,,#****//****************************\nPRIVMSG #bot :****************,*,*,*,,,,,,,,,,,/#####**///*///(@&&&&%(//**************************//////(((&&@@@&#/*******/*****,(****//////////////////////////////\nPRIVMSG #bot :**************,*,***,*,,,,,,,,,,,/#####,**//**/*/@&&&&%(//************************//////(((((#&&@@@&%************,,(***///**//////////////////////////\nPRIVMSG #bot :************,**,,**,,*,,,,,,,,,,,/#####***///*/*/(&&@&////(%%###(/******/*********///////((((&&@@@@(/**************#(****/////////////////////////////\nPRIVMSG #bot :*************,*,,*,*,,,,,,,,*,,,,/#####**//*/////&@&&(/((((((###%&&&&#(((///////////////(((#%@@@@@@***************((***///////////////////////////////\nPRIVMSG #bot :********************,**,,,,*,,,,,*#####**///////#@@&#///((#&&@@@&&&%%##///((#%&&@@&&&%&%((##&&@@@@/*,*************(##*///**///////////////////////////\nPRIVMSG #bot :**/*****************,**,,,*,*,,,**#####**//////(%#&&(///////((###%#&(//***/#%&&&@&&&%##%&%(#@@@@@*****************###******////////////////*//////////\nPRIVMSG #bot :***********************,,**,*,,,**####(*/*//////((%&(///****////((/*/*****/(((##@&##&@&%%#((@@@@&/,,,,,**********/##(*////////////////////////////////\nPRIVMSG #bot :,,,,,,,,,,,,,*********//,****,,,**####*,/////////#%#(///***********//*****/((//((##((((((((#@@&%**,,,************###*/////////////////////////////////\nPRIVMSG #bot :&&&&&&&&&&@%((((((#%(/********,***%%%%***,,*,,,*///((///******////(**/**///(((/////////(((#%@@&&*,************///*#(**////////////////////**//////////\nPRIVMSG #bot :&&&&&&&&&&@%((#####%((************###############///(/////////////(#&@&%&&&#(((///////(((#%&&((,,,,,,,,,,,,,,,,,,,,/,,,*,,,,,,*********,***,*********/\nPRIVMSG #bot :@@@@@@&&&&@%(((/***(****,*,,******%%%#%%%%%%%%%%%%%&/(((/(((((////((%#%%%&&%///((////(((##%%((///////////###############%%%%%%%%%%%%%%%%%&&&&&%%%&%%#(\nPRIVMSG #bot :%%&%%@&&&&@#*******(,******,******#(########%%%####%//((/////(((////(///(((((#(/((((((###%((((/(/(((/////%&&&&&&&&@&&@@@&%%%%#%%%%%&&&&&&&&&&&%%%&%%#(\nPRIVMSG #bot :**********((*******(,*,*,,*,***********///////((/(((((///(/*//(///////((#%&&%###(((####(%%%*,,,,,,,*////*####@&&&#%%@@@@&%%%%#%%%%%&&&&&&&&&&&%%%@%&##\nPRIVMSG #bot :**/*/*////#(*******(,*,,,,,,*************************((/((////////((######(((//(//((#((#*,,,,,,,,,,,*,,,,/(///**/////(((((((/////(((((((((((((((###%(*\nPRIVMSG #bot :%%%%@&&&&&@#*,***,*/,,,,,,********(##############%&%%#(((((///////**///////////((((##(#/,,,,,,,,,,,,,,,,,******************************************#/*\nPRIVMSG #bot :%%%%@&&&%%@#*****,*/,,,**,*,******(###############&%&%/(###((////////////////(((((###%(*,,,*,,,,,,,,,,,,,####&@@&&###%%%&%%%%%%%%%&&&&&&&&&&&&%%&@%%/*\nPRIVMSG #bot :%%%%&&&&%%@#*,**,,*/,,,,**********##(#(###########%%%%//((#%&%######%#####((#####%%&&&&&,,,,,,,,,,,*/%&%&%%%%%&&&%##%%#%%%%%%%%%%&&&&&&&&&&&&&%%#%%%/*\nPRIVMSG #bot :%%%@&&&&&&@#*******/,,,***********%##############%%%&*(((((##%&&&@@&&&@&&&&&&&&&&%%&&&&@@@&&&&&&&&&&&&&&&&&&&&&&&&&%%%%%%%%%%%%%%&&&&&&&&&&&&&%%#%%#/*\nPRIVMSG #bot :%@&&%@@&%&@#*,******,******///////#((///(((((((###%&&*/((((((###%%&&&&&&&&&%%%%%%%#*&&&&&@@@@@&&@&&&&&&&&&&&&&&&&&@&&&&&&%%%&%%%%&&&&&&&&&&&&&%%#%%#/*\nPRIVMSG #bot :&%%%%@@&%&@#*,***********//((((((#%%@&&&%%%%&@@@@&&&&***,(((((#####%%%%%%%%%%%%%#(,*&&&&&&&@@@@@&@&&&&&&&&&&&&&&&&&&&&&&%%%%&%%%&&&&&&&&&&&&&%%%#%%%/*\nPRIVMSG #bot :@&&@@@&&&&@#***********//((((((((#&&&%%%%%%%%&@@&&&&&&********(((#############(((*,*&&&&&&&&&@@@@&&&&&&&&&&&&&&&&&&@&&&&&%%%%%%%&&&&&&&&&&&&&&%%#%%%/*\nPRIVMSG #bot :%%%%%@@&%&@#*******/**/((((((#%%%%%%%%%%%%%%%%&@@@&&&&&&********,*/#(######(///(*,,*&&&&&&&&&&@@@@&&&&&&&&&&&&&%&&&@&&&&&%%%%%%%%&&&&&&&&&&&&%%%#%%%/*\nPRIVMSG #bot :%%%%%&@&&&@#*******///(((%%%%%%%%%%%%%%%%%%%%%%&@@@@@@@&&&********,,,/,/(/////(,,,,*&%&&&&&&&&&&&@&&&&&@&&&&&&&&&&&&&&&&&&&%&%%%&&&&&&&&&&&&&%%%#%&%//\nPRIVMSG #bot :%%%%%&@&&&@#*****//((%%%%%%%%%%%%%%%%%%%%%%%%%%&%@@@@@@@@&&&*******###((((///(,(#%%*&&%&&&&&&&&&@&&&&&@@&&&&&&&&&&&&@&&&&&&&&%%%&&&&&&&&&&&%%%%%#&&%//\nPRIVMSG #bot :%%%%%&@&&&@#****/((#%&&&&%&%%%%&&%%%%%&%&%&%%%%%%&@@@@@@@@@&&&#***##((//////*%/*,%%%&&&&&&&&&&&@&&&&&@@@&&&&&&&&&&&&@&&&&&&&&&%%%&&&&&&&&&%#%%%%#&&%//\nPRIVMSG #bot :%%%%%%@&&&@#***/((#&&&&&&&&&&&&%&&&&%%%%%&&&%%%%&%&&&@@@@&&&&&&&%*,,///////,/*/*****&&&&&&&&&&&&&&&&&@@&&&&@@&&&&&&&&&&&&&@@&&&%&&&&&&&&&&%#%%%%#&&%/(\nPRIVMSG #bot :%%%%%%@&%&@#***/((&&&&&&&&&&&&&&&%&&&&&&&&&%%%&%%%%&&&&&&&&&&&&&&&%,,,,,****,,*,,*,,%&&&&&%&&&&&&&&&&@@&&&@@&&&&&&&&&&@@@&&&&&&&&&&&&&&&&&%%%%%%#&&%/(\nPRIVMSG #bot :%%%%%%@&%&@#*///((&&&&&&&&&&&&&&&&&&&&&%&&&&&&&&&&&%&&@&&&&&&&&&&&&%#,,,,***,,,,,,*,#%%&%%%%%&%%%&&&&@&&&&@&&&@&&&@@&&&&&&&&&&&&&&&&&&&&&&&&&%%%#&&%/(\nPRIVMSG #bot :%%%%%%@&%&@#////((&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@&&&&&%&&&&&*,,,/,,,,..,,.,%%%%%%%%&%%%%%%%@&&&&@&@@&&@@@&&&&&&&&%&&&&&&&%#(/*,,,,,,*%#%&%/(\nPRIVMSG #bot :%%%##%&&%&&#////((&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&,,*,....,...,%%%%%%%%%%%&%&%%@%&&@&@@&&@@&&&&&&&&%%%%&%&&&////**/////((/#%&%/(\nPRIVMSG #bot :%%%%%%@&%&&#////((&&&&&&&&&&&&&&&&&&&&&@&&&&&&&&&&&&&&&&&&&&&@&&&&&&&&&&&#,...,......*%%%&&%&&&%%&&%%&&&&@@@&&@@&&&&&&&%&&%&&&&&&&&&///////(/((//%&%/(\nPRIVMSG #bot :%%%%%%&&%&&#////*,&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@&&&&&&@&&&&&&&&&&&,.........,%%%%&%%&%&&&%%%&&&&@@@&@@&&&&&&%%%%&%%%%%%%&&&&,*(((/////*/%&%((\nPRIVMSG #bot :(((//**,,,,,,@@@,,%&&&&&&&&&&&&&&&&&&&&&&@&&&&&&&&&&&&&@@@@&&&&&&@&&&&&&%&&&%........,*%%%%%%%&%%&%%%&&&@@@@@@&&&&&&&&%&%&%&&%%%&&&&&&***,,*/////(&%((\nPRIVMSG #bot :,,*,,,,,,,,,*@@@@@&&&&&&&&@@@@@@@@&&&@@@@@@@@&&&&&&&&&&@@@@@@@@@&&&@&&%&&&%&&%,.......,%%&%&%%%%%&&&%&&&@@@@@&&&&&&&&%%%%%%%%%%%%&&&&&&&**,,,,,**/***#\nPRIVMSG #bot :,,,,,,,,,,*/#@@@@@@&&&&&@&&&&&&&&@@@@@@@@@@@@@@@&&&&&&&&&@@@@@@@@@&&@&&&&&&&&&&,,,,,.,*/%&&&%&&&&&%%%&&&@@@@@&&&&&&&&&&&%%%%%&&&&&%%&&&&&,,*,,,,,*/((%\nPRIVMSG #bot :,,,,,,,,*//((@@@@@@&&&&&&&&&@@&&&&&&&&&&&&@@@@@@@@&&&&&&@@@@@@@@@@&&&@@&&&&&&&&&**,,,,,(#&&&&%&&&&&&%&&&@@@@@&&&&&&&&&&%%&&&&%%%%&&&&&&%&,**,,,,,,*//#\nPRIVMSG #bot :,,,,*,***//##@@@@@&&&&&&&&&&&&&&&&&&&&&&&&%&&&@@@@@@&&&&&&@@@@@@@@&&&&@@@&&&&&&&(,,,*,,,%#&&&&&&%&&%&%&&@@@@@@&&&&&&&&&%&&%%%%%%%%%%%&&&&&%,**,,***//#\nPRIVMSG #bot :,,*((//*/(*%@@@@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@@@@@&@@@@@@&@@&&&&&&&@@&&&&&&&,,,,,*,,%%&&&&&&&&&&&@&@@@@@&&&&&&&&&&&&&&&%%%%%%%%%%%%&&&&#******//#\nPRIVMSG #bot :**/(///***/@@@&&@@@&&&&&&&&&&&&&&&&&&&&@@&&&&&&&&&@@@@@&@@&@@@@@@@@&&&&&&@@@&&&&&&,,*,,*,/%&&&&&&&&&%&@&@@@@@&&&&&@&&&&&&%%%%%%%%%%%%%&&&&&&&*******/#\nPRIVMSG #bot :,,,**/////(@@@&&@@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@@&&@@@@@@@@@@&&&&&&@@@&&&&&,,,*,,,,(%&&&&&&&&&%@@&@@@@@&&&&&&&&&&%%%%%%%%%%%%%%%%&&&&&*******(#\nPRIVMSG #bot :,,,,*//(((&@@&&&&&@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@@&@@@@@@@@@@@@&&&&&@@@&&&&&,,,,,,,/(%&&&&&&&&&&@@@@@@@@&&&&&&&&&&%%%%%%%%%%%%&&%&&%&**********\nPRIVMSG #bot :,,*,*/((#%@@@%&&&&@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@@@@@@@@@@@@@@@&&&&&@@@&&&&*,,,.,,,/#%&&&&&&&&&@@@@@@@&&&&&&&&&%%%%%%%%%%%%%%&&&&&&&*****/////\nPRIVMSG #bot :,,***/(##%@@&%&&&&@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@@@@@@@@@@@@@@&&@&&@@@@&&(*,,,,,,*(##&&&&&&&&&@@@@@@&&&&&&%#((/((#(/*,%%%%%%%&%%%&%*/////###\nPRIVMSG #bot :,****/##%%@@@&&&&@@@@@&&&&@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@@@@@@@@@@@@@@@@@@@@@@@&&*,,,,,,*((#(&&&&&&&&@@@@@@@@&&%&*/###(##(###%%,#&%%%%&%&#////((%%%\nPRIVMSG #bot :*****(#%%&@@&&&&&&@@@@@&&&@@@@@@&&&&&&&&&&&&&&&&&&&&&&&@@@&&&@@@@@@@@@@@@@@@@@&&@@&&**,,,,,,*((((&&&&&&&&@@@@@@@%&##&&&&(*,/////((&,,&@@%%&&*//////&&&\nPRIVMSG #bot :****/(#%&&@@@&&&&@@@@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@@@@@@@@@@&&&&&&&@@&***,,,,,,,/((/%&&&&&&@@@@@@&&@/**************/&&,*@@@%&**////(//&&\nPRIVMSG #bot :****/(#%%&%@@&%%&&&@@@@@&&&&&&&&&&&&&&&&&&&&&&&&&&%%&&&&&&&&&&&@@@@@@@@@@@&&&&&&&@@&**,,,,,,,,,*(*/#&&&&&&@@@@&&/********************/%&@@%**///(((/(&\nPRIVMSG #bot :****/(#%%&&@@%%&&&&@@@@@@@&&&&&&&&&&&&&&&&&&&&&&&%&&&@@@@@@@&&&@@@@@@@@@&&&&&&&&&@@&*****/,,***,/(**#&&&&&@@@@@(/*********************,****%**//%%//(&\nPRIVMSG #bot :*****(#%%&&@@&&&&&&&@@@@@@@&&&&&&&&&&&&&&&&&&&&&&&@@@&&&&&&&&&&&&@@@@@@@@@&&&&&&@@@&//,**,*,,,,,,/((,,/&&&&@@@&/*****************************///&&///%\nPRIVMSG #bot :*****/#%%&&&@&&&&&&&&@@@@@@@@&&&&&&&&&&&&&&&&&&@@@&&&&&&&&&&&%&&&&&&@@@@@&&&&&&@@@@&**,,**,*,,,,,,,///**/#@&&%*********************************/&%(#%%\nPRIVMSG #bot :****//#%%&&&@@&&&&&&&@@@@@@@@@&&&&&@&&&&&&&&&&@@@&&&&&&&&&&&%&&%%%%%%%%%&%&%&&&@@@&**//**,,**,,,,,,,,***,*/////***//****************/*****((****////%%\n");
    client.bsend(tibo);
}