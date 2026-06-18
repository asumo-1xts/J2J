<h1 align="center">

Just the Two of ~~US~~ JIS

</h1>

<div align="center">

[![QMK](https://img.shields.io/badge/QMK-%23333330?style=flat&logo=qmk&logoColor=white)](https://qmk.fm/)
[![KiCad](https://img.shields.io/badge/-%23314CB0?style=flat&logo=kicad&logoColor=white&logoSize=auto)](https://downloads.kicad.org/kicad/windows/explore/stable)
[![FreeCAD](https://img.shields.io/badge/FreeCAD-%23418FDE?style=flat&logo=freecad&logoColor=white)](https://www.freecad.org/)
[![License: GPL-3.0](https://img.shields.io/badge/License-GPL--3.0-green.svg)](/LICENSE)

**_We can make it if we try ..._**

![Layer #1](keyboard-layout.png)

</div>

## Spec

| 項目            | 仕様                                                                                           |
| --------------- | ---------------------------------------------------------------------------------------------- |
| 接続・給電      | USB Type-C                                                                                     |
| レイアウト      | ロープロファイル<br/>**JIS-like US** 87キー                                                    |
| キーマップ変更  | ✅ - [Vial](https://get.vial.today/), [Pipette](https://github.com/darakuneko/pipette-desktop) |
| ホットスワップ  | ✅                                                                                             |
| LEDライティング | ✅                                                                                             |

## BOM

| 部品                           |        数量 |
| ------------------------------ | ----------: |
| PCB基板                        |     左右1組 |
| Kailh Choc V2 キースイッチ     |        87個 |
| Kailh Choc V2 HotSwapソケット  |        87個 |
| Kailh Choc V2 スタビライザー   |         4個 |
| SK6812MINI-E フルカラーLED     |        87個 |
| ケース                         | 左右上下1組 |
| M2 12mmタップねじ              |        42本 |
| ロープロファイル用キーキャップ |         1組 |
| 3.5mm TRRSケーブル             |         1本 |
| USB Type-Cケーブル             |         1本 |

## Notice

- 故障を避けるため、TRRSケーブルの着脱はUSB Type-Cケーブルを抜いた状態で行ってください。
- コンパイルの際は、Vial-QMKリポジトリにおける下記ファイルを手元で編集する必要があります。
  - `/quantum/action.c`
  - `/quantum/action_tapping.c`
  - `/quantum/action_tapping.h`

  詳細: 準備中
