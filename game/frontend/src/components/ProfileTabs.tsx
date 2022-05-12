import React from "react";
import { Tab } from "@headlessui/react";
import Graph from "./Graph";
import History from "./History";

interface Props {
  winsByTries: number[];
}

export default function ProfileTabs({ winsByTries }: Props) {
  return (
    <div className="flex flex-col items-center justify-center w-full">
      <Tab.Group>
        <Tab.List className="flex items-center justify-center border-2 border-gray-600 rounded-lg text-md md:text-lg lg:text-xl">
          <Tab
            className={({ selected }) =>
              selected ? "tab--selected" : "tab--default"
            }
          >
            Graphe
          </Tab>
          <Tab
            className={({ selected }) =>
              selected ? "tab--selected" : "tab--default"
            }
          >
            Historique
          </Tab>
        </Tab.List>
        <Tab.Panels className="w-full py-12">
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
