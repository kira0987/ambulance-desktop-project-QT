import QtQuick 2.0
import QtLocation 5.14
import QtPositioning 5.14

Rectangle {
    Plugin {
        id: mapPlugin ;
        name: "osm" ;
    }

    Map {
        id : mapView;
        anchors.fill : parent;
        plugin : mapPlugin;
        center : QtPositioning.coordinate(36.89953484183019, 10.189579629768238);
        zoomLevel : 12 ;



        MapQuickItem {
            coordinate: QtPositioning.coordinate(36.8981492436939, 10.189611001937458);
            sourceItem: Column {
                Image {
                    source: "https://cdn-icons-png.flaticon.com/512/3209/3209005.png"
                    width: 32
                    height: 32
                }
                Text {
                    text: "Ambulance"
                    font.pixelSize: 12
                }
            }
        }

        MapQuickItem {
            coordinate: QtPositioning.coordinate(36.8037956926629, 10.161467504030787);
            sourceItem: Column {
                Image {
                    source: "https://cdn-icons-png.flaticon.com/512/4320/4320350.png"
                    width: 32
                    height: 32
                }
                Text {
                    text: "Hospital Charles Nicolle"
                    font.pixelSize: 12
                }
            }
        }
        MapQuickItem {
            coordinate: QtPositioning.coordinate(36.886875, 10.325825);
            sourceItem: Column {
                Image {
                    source: "https://cdn-icons-png.flaticon.com/512/4320/4320350.png"
                    width: 32
                    height: 32
                }
                Text {
                    text: "Mongi Slim Hospital"
                    font.pixelSize: 12
                }
            }
        }

        MapQuickItem {
            coordinate: QtPositioning.coordinate(35.504900, 11.062330);
            sourceItem: Column {
                Image {
                    source: "https://cdn-icons-png.flaticon.com/512/4320/4320350.png"
                    width: 32
                    height: 32
                }
                Text {
                    text: "Tahar Sfar Hospital"
                    font.pixelSize: 12
                }
            }
        }

        MapQuickItem {
            coordinate: QtPositioning.coordinate(35.834573, 10.618382);
            sourceItem: Column {
                Image {
                    source: "https://cdn-icons-png.flaticon.com/512/4320/4320350.png"
                    width: 32
                    height: 32
                }
                Text {
                    text: "Farhat Hached Hospital"
                    font.pixelSize: 12
                }
            }
        }

        MapQuickItem {
            coordinate: QtPositioning.coordinate(36.799983, 10.188489);
            sourceItem: Column {
                Image {
                    source: "https://cdn-icons-png.flaticon.com/512/4320/4320350.png"
                    width: 32
                    height: 32
                }
                Text {
                    text: "Habib Thameur Hospital"
                    font.pixelSize: 12
                }
            }
        }

        MapQuickItem {
            coordinate: QtPositioning.coordinate(36.870010, 10.296189);
            sourceItem: Column {
                Image {
                    source: "https://cdn-icons-png.flaticon.com/512/4320/4320350.png"
                    width: 32
                    height: 32
                }
                Text {
                    text: "Kassab Institute of Orthopedics"
                    font.pixelSize: 12
                }
            }
        }
        MapQuickItem {
            coordinate: QtPositioning.coordinate(36.802496150084295, 10.154560935294054);
            sourceItem: Column {
                Image {
                    source: "https://cdn-icons-png.flaticon.com/512/4320/4320350.png"
                    width: 32
                    height: 32
                }
                Text {
                    text: "RABTA Hospital"
                    font.pixelSize: 12
                }
            }
        }


    }
}
