package com.jnngl.packet;

import com.jnngl.totalcomputers.MapColor;
import org.bukkit.entity.Player;

import java.awt.image.BufferedImage;
import java.lang.reflect.Constructor;
import java.util.ArrayList;
import java.util.Collection;

public class MapPacketSender_R1_9 extends PacketSender implements MapPacketSender {

    private final Constructor<?> packet;

    public MapPacketSender_R1_9() throws ReflectiveOperationException {
        super();

        Class<?> packetClass = Class.forName(pkg+".PacketPlayOutMap");
        packet = packetClass.getConstructor(int.class, byte.class, boolean.class, Collection.class, byte[].class, int.class, int.class, int.class, int.class);
    }

    @Override
    public void sendMap(Player player, int mapId, BufferedImage data) {
        try {
            Object packet = createPacket(mapId, data);
            sendPacket(player, packet);
        } catch (Throwable e) {
            System.err.println("Failed to create/send packet");
            System.err.println(" -> "+e.getMessage());
        }
    }

    @Override
    public Object createPacket(int mapId, BufferedImage data) throws ReflectiveOperationException {
        return packet
                .newInstance(mapId, (byte)0, false, new ArrayList<>(), MapColor.toByteArray(data), 0, 0, 128, 128);
    }

    @Override
    public void modifyPacket(Object packet, BufferedImage tile) throws ReflectiveOperationException {

    }

}