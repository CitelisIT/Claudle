import { Fragment, useContext } from "react";
import { Dialog, Listbox, Switch, Transition } from "@headlessui/react";
import { XIcon } from "@heroicons/react/outline";
import { SelectorIcon } from "@heroicons/react/solid";
import { SettingsContext } from "../App";

interface Props {
  settingsOpen: boolean;
  setSettingsOpen: React.Dispatch<React.SetStateAction<boolean>>;
}

const lengths = [4, 5, 6, 7, 8, 9, 10];
const tryNumbers = [4, 5, 6, 7, 8, 9, 10];
const layouts = ["qwerty", "azerty"];

export default function Settings({ settingsOpen, setSettingsOpen }: Props) {
  const settingsContext = useContext(SettingsContext);

  return (
    <Transition
      as={Fragment}
      appear
      show={settingsOpen}
      enter="transform origin-top-right transition ease-in-out duration-100"
      enterFrom="scale-0 opacity-0"
      enterTo="scale-100 opacity-100"
      leave="transform origin-top-right transition ease-in-out duration-100"
      leaveFrom="scale-100 opacity-100"
      leaveTo="scale-0 opacity-0"
    >
      <Dialog
        open={settingsOpen}
        onClose={() => setSettingsOpen(false)}
        className="fixed p-4 m-auto text-gray-200 bg-gray-900 border border-gray-600 rounded-lg shadow-2xl right-4 top-20 h-fit"
      >
        <Dialog.Overlay />

        <div className="flex justify-between flex-center">
          <Dialog.Title className="text-base font-semibold md:text-lg lg:text-xl">
            Réglages
          </Dialog.Title>
          <button onClick={() => setSettingsOpen(false)}>
            <XIcon className="w-5 h-5 lg:h-6 lg:w-6" />
          </button>
        </div>
        <hr className="h-2 my-4 border-t-2 border-gray-700" />
        <div className="grid grid-cols-2 gap-x-2 gap-y-4">
          <span className="text-base md:text-lg lg:text-xl justify-self-left">
            Longueur
          </span>
          <div className="text-lg justify-self-end">
            <Listbox
              value={settingsContext.size}
              onChange={settingsContext.setSize}
            >
              <div className="relative">
                <Listbox.Button className="flex items-center justify-between w-full gap-2">
                  <span className="relative">{settingsContext.size}</span>
                  <span className="relative">
                    <SelectorIcon className="w-5 h-5" aria-hidden="true" />
                  </span>
                </Listbox.Button>
                <Listbox.Options className="absolute z-10 text-right bg-gray-900 border border-gray-600 rounded">
                  {lengths.map((len) => (
                    <Listbox.Option
                      key={len}
                      value={len}
                      disabled={false}
                      className={({ active }) =>
                        `text-gray-200 relative px-2 py-1 ${
                          active ? "bg-gray-600" : ""
                        }`
                      }
                    >
                      {len}
                    </Listbox.Option>
                  ))}
                </Listbox.Options>
              </div>
            </Listbox>
          </div>
          <span className="text-base md:text-lg lg:text-xl justify-self-left">
            Nombre d'essais
          </span>
          <div className="text-lg justify-self-end">
            <Listbox
              value={settingsContext.tries}
              onChange={settingsContext.setTries}
            >
              <div className="relative">
                <Listbox.Button className="flex items-center justify-between w-full gap-2">
                  <span className="relative">{settingsContext.tries}</span>
                  <span className="relative">
                    <SelectorIcon className="w-5 h-5" aria-hidden="true" />
                  </span>
                </Listbox.Button>
                <Listbox.Options className="absolute z-10 text-right bg-gray-900 border border-gray-600 rounded">
                  {tryNumbers.map((num) => (
                    <Listbox.Option
                      key={num}
                      value={num}
                      disabled={false}
                      className={({ active }) =>
                        `text-gray-200 relative px-2 py-1 ${
                          active ? "bg-gray-600" : ""
                        }`
                      }
                    >
                      {num}
                    </Listbox.Option>
                  ))}
                </Listbox.Options>
              </div>
            </Listbox>
          </div>
          <span className="text-base md:text-lg lg:text-xl justify-self-start">
            Mode difficile
          </span>
          <Switch
            checked={settingsContext.hardMode}
            onChange={settingsContext.setHardMode}
            className={`${
              settingsContext.hardMode ? "bg-green-600" : "bg-gray-600"
            } relative inline-flex items-center h-6 rounded-full w-11 justify-self-end`}
          >
            <span className="sr-only">Activer le mode difficile</span>
            <span
              className={`${
                settingsContext.hardMode ? "translate-x-6" : "translate-x-1"
              } inline-block w-4 h-4 transform bg-white rounded-full`}
            />
          </Switch>
          <span className="text-base md:text-lg lg:text-xl justify-self-start">
            Clavier
          </span>
          <div className="text-lg justify-self-end">
            <Listbox
              value={settingsContext.layout}
              onChange={settingsContext.setLayout}
            >
              <div className="relative">
                <Listbox.Button className="flex items-center justify-between w-full gap-2">
                  <span className="relative">{settingsContext.layout}</span>
                  <span className="relative">
                    <SelectorIcon className="w-5 h-5" aria-hidden="true" />
                  </span>
                </Listbox.Button>
                <Listbox.Options className="absolute z-10 text-right bg-gray-900 border border-gray-600 rounded">
                  {layouts.map((layout) => (
                    <Listbox.Option
                      key={layout}
                      value={layout}
                      disabled={false}
                      className={({ active }) =>
                        `relative px-2 py-1 text-gray-200 ${
                          active ? "bg-gray-600" : ""
                        }`
                      }
                    >
                      {layout}
                    </Listbox.Option>
                  ))}
                </Listbox.Options>
              </div>
            </Listbox>
          </div>
        </div>
      </Dialog>
    </Transition>
  );
}
