import React from "react";
import { Tab } from "@headlessui/react";
import Graph from "./Graph";
import History from "./History";

interface Props {
  winsByTries: number[];
}

export default function ProfileTabs({ winsByTries }: Props) {
  return (
    <div className="flex items-center justify-center w-full">
      <Tab.Group>
        <Tab.List>
          <Tab className="text-gray-200">Graphe</Tab>
          <Tab className="text-gray-200">Historique</Tab>
        </Tab.List>
        <Tab.Panels>
          <Tab.Panel>
            <Graph winsByTries={winsByTries} />
          </Tab.Panel>
          <Tab.Panel>
            <History />
          </Tab.Panel>
        </Tab.Panels>
      </Tab.Group>
    </div>
  );
}
