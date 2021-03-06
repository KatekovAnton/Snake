/****************************************************************************
 Copyright (c) 2010-2012 cocos2d-x.org
 Copyright (c) 2008-2010 Ricardo Quesada
 Copyright (c) 2011      Zynga Inc.

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

var audioEngine = cc.AudioEngine.getInstance();

if ( cc.config.deviceType == 'browser' ) {
    var MUSIC_FILE = "res/background";
    var EFFECT_FILE = "res/effect2";
} else {
    var MUSIC_FILE = "Cyber Advance!.mp3";
    var EFFECT_FILE = "cowbell.wav";
}


var DenshionTests = [
    {
        title:"playBackgroundMusic",
        playFunc:function () {
            return new playBackgroundMusic();
        }
    },
    {
        title:"stopBackgroundMusic",
        playFunc:function () {
            return new stopBackgroundMusic();
        }
    },
    {
        title:"pauseBackgroundMusic",
        playFunc:function () {
            return new pauseBackgroundMusic();
        }
    },
    {
        title:"resumeBackgroundMusic",
        playFunc:function () {
            return new resumeBackgroundMusic();
        }
    },
    {
        title:"rewindBackgroundMusic",
        playFunc:function () {
            return new rewindBackgroundMusic();
        }
    },
    {
        title:"isBackgroundMusicPlaying",
        playFunc:function () {
            return new isBackgroundMusicPlaying();
        }
    },
    {
        title:"playEffect",
        playFunc:function () {
            return new playEffect();
        }
    },
    {
        title:"playEffectRepeatly",
        playFunc:function () {
            return new playEffectRepeatly();
        }
    },
    {
        title:"stopEffect",
        playFunc:function () {
            return new stopEffect();
        }
    },
    {
        title:"unloadEffect",
        playFunc:function () {
            return new unloadEffect();
        }
    },
    {
        title:"addBackgroundMusicVolume",
        playFunc:function () {
            return new addBackgroundMusicVolume();
        }
    },

    {
        title:"subBackgroundMusicVolume",
        playFunc:function () {
            return new subBackgroundMusicVolume();
        }
    },

    {
        title:"addEffectsVolume",
        playFunc:function () {
            return new addEffectsVolume();
        }
    },

    {
        title:"subEffectsVolume",
        playFunc:function () {
            return new subEffectsVolume();
        }
    },

    {
        title:"pauseEffect",
        playFunc:function () {
            return new pauseEffect();
        }
    },

    {
        title:"resumeEffect",
        playFunc:function () {
            return new resumeEffect();
        }
    },

    {
        title:"pauseAllEffects",
        playFunc:function () {
            return new pauseAllEffects();
        }
    },

    {
        title:"resumeAllEffects",
        playFunc:function () {
            return new resumeAllEffects();
        }
    },

    {
        title:"stopAllEffects",
        playFunc:function () {
            return new stopAllEffects();
        }
    }

];

CocosDenshionTest = cc.Layer.extend({
    _itemMenu:null,
    _beginPos:cc.p(0,0),
    isMouseDown:false,
    _testCount:0,
    ctor:function () {
        // add menu items for tests
        cc.associateWithNative( this, cc.Layer );
        this.init();

        this._itemMenu = cc.Menu.create();
        var s = cc.Director.getInstance().getWinSize();
        for (var i = 0; i < DenshionTests.length; i++) {
            var label = cc.LabelTTF.create(DenshionTests[i].title, "Arial", 24);
            var menuItem = cc.MenuItemLabel.create(label, this, this.menuCallback);
            this._itemMenu.addChild(menuItem, i + 10000);
            menuItem.setPosition(cc.p(s.width / 2, (s.height - (i + 1) * LINE_SPACE)));
        }
        this._testCount = i;
        this._itemMenu.setContentSize(cc.size(s.width, (this._testCount + 1) * LINE_SPACE));
        this._itemMenu.setPosition(cc.p(0,0));
        this.addChild(this._itemMenu);

        var t = cc.config.deviceType;
        if( t == 'browser' )  {
            this.setTouchEnabled(true);
            // this.setKeyboardEnabled(true);
        } else if( t == 'desktop' ) {
            this.setMouseEnabled(true);
        } else if( t == 'mobile' ) {
            this.setTouchEnabled(true);
        }

        // set default volume
        audioEngine.setEffectsVolume(0.5);
        audioEngine.setBackgroundMusicVolume(0.5);
    },
    menuCallback:function (sender) {
        var idx = sender.getZOrder() - 10000;
        // create the test scene and run it
        var scene = DenshionTests[idx].playFunc();
    },
    onTouchesMoved:function (touches, event) {
        if (this.isMouseDown) {
            var touchLocation = touches[0].getLocation();
            var nMoveY = touchLocation.y - this._beginPos.y;
            var curPos = this._itemMenu.getPosition();

            var nextPos = cc.p(curPos.x, curPos.y + nMoveY);
            var winSize = cc.Director.getInstance().getWinSize();
            if (nextPos.y < 0.0) {
                this._itemMenu.setPosition(cc.p(0,0));
                return;
            }

            if (nextPos.y > ((this._testCount + 1) * LINE_SPACE - winSize.height)) {
                this._itemMenu.setPosition(cc.p(0, ((this._testCount + 1) * LINE_SPACE - winSize.height)));
                return;
            }

            this._itemMenu.setPosition(nextPos);

            this._beginPos = cc.p(0, touchLocation.y);
        }
    },
    onTouchesBegan:function (touches, event) {
        if (!this.isMouseDown) {
            this._beginPos = touches[0].getLocation();
        }
        this.isMouseDown = true;
    },
    onTouchesEnded:function () {
        this.isMouseDown = false;
    },

    onMouseDragged : function( event ) {
        var delta = event.getDelta();
        var current = this._itemMenu.getPosition();
        this._itemMenu.setPosition( cc.p( current.x, current.y + delta.y ) );
        return true;
    },
    onExit:function () {
        this._super();
        audioEngine.end();
    }
});

CocosDenshionTestScene = TestScene.extend({
    runThisTest:function () {
        audioEngine = cc.AudioEngine.getInstance();
        var layer = new CocosDenshionTest();
        this.addChild(layer);
        cc.Director.getInstance().replaceScene(this);
    }
});

var soundId = null;

var playBackgroundMusic = function () {
    cc.log("play background music");
    audioEngine.playBackgroundMusic(MUSIC_FILE, false);
};

var stopBackgroundMusic = function () {
    cc.log("stop background music");
    audioEngine.stopBackgroundMusic();
};

var pauseBackgroundMusic = function () {
    cc.log("pause background music");
    audioEngine.pauseBackgroundMusic();
};

var resumeBackgroundMusic = function () {
    cc.log("resume background music");
    audioEngine.resumeBackgroundMusic();
};

var rewindBackgroundMusic = function () {
    cc.log("rewind background music");
    audioEngine.rewindBackgroundMusic();
};

// is background music playing
var isBackgroundMusicPlaying = function () {
    if (audioEngine.isBackgroundMusicPlaying()) {
        cc.log("background music is playing");
    }
    else {
        cc.log("background music is not playing");
    }
};

var playEffect = function () {
    cc.log("play effect");
    soundId = audioEngine.playEffect(EFFECT_FILE);
};

var playEffectRepeatly = function () {
    cc.log("play effect repeatly");
    soundId = audioEngine.playEffect(EFFECT_FILE, true);
};

var stopEffect = function () {
    cc.log("stop effect");
    audioEngine.stopEffect(soundId);
};

var unloadEffect = function () {
    cc.log("unload effect");
    audioEngine.unloadEffect(EFFECT_FILE);
};

var addBackgroundMusicVolume = function () {
    cc.log("add bakcground music volume");
    audioEngine.setBackgroundMusicVolume(audioEngine.getBackgroundMusicVolume() + 0.1);
};

var subBackgroundMusicVolume = function () {
    cc.log("sub backgroud music volume");
    audioEngine.setBackgroundMusicVolume(audioEngine.getBackgroundMusicVolume() - 0.1);
};

var addEffectsVolume = function () {
    cc.log("add effects volume");
    audioEngine.setEffectsVolume(audioEngine.getEffectsVolume() + 0.1);
};

var subEffectsVolume = function () {
    cc.log("sub effects volume");
    audioEngine.setEffectsVolume(audioEngine.getEffectsVolume() - 0.1);
};

var pauseEffect = function () {
    cc.log("pause effect");
    audioEngine.pauseEffect(soundId);
};

var resumeEffect = function () {
    cc.log("resume effect");
    audioEngine.resumeEffect(soundId);
};

var pauseAllEffects = function () {
    cc.log("pause all effects");
    audioEngine.pauseAllEffects();
};
var resumeAllEffects = function () {
    cc.log("resume all effects");
    audioEngine.resumeAllEffects();
};
var stopAllEffects = function () {
    cc.log("stop all effects");
    audioEngine.stopAllEffects();
};
